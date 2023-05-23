#ifndef TINYSTLBYCIEL_TEST_CIEL_MEMORY_TEST_H_
#define TINYSTLBYCIEL_TEST_CIEL_MEMORY_TEST_H_

#include <iostream>
#include <ciel/memory.h>

#ifndef CHECK
#define CHECK(x) if (!(x)) { std::cerr << "Line " << __LINE__ << " : " << #x << " failed.\n"; }
#endif

namespace memory_test_details {
	struct Task {
	public:
		static Task* create_worker() {
			ciel::unique_ptr<Task> tmp{new Task{}};
			Task* res = tmp.get();
			res->accept(ciel::move(tmp));
			return res;
		}
		void work_and_die() {
//			std::cout << "Working...\n";
			ptr.reset();
		}
//		~Task() { std::cout << "Dying...\n"; }
	private:
		ciel::unique_ptr<Task> ptr;    //ptr == this
		void accept(ciel::unique_ptr<Task>&& tmp) {
			ptr = ciel::move(tmp);
		}
	};
	struct A {};
	struct B : A {};
	struct C : private B {};
	struct EmptyDeleter {
		void operator()(...) {}
	};
}

void memory_test() {
	using namespace memory_test_details;

	//unique_ptr
	Task* t = Task::create_worker();
	t->work_and_die();

	ciel::unique_ptr<int> ptr1;
	ciel::unique_ptr<int> ptr2(nullptr);
	int* id{};
	ciel::unique_ptr<int> ptr3(id);
	CHECK(ptr1 == nullptr);
	CHECK(ptr2 == nullptr);
	CHECK(ptr3 == nullptr);

	ciel::unique_ptr<int> ptr4(new int{1});
	CHECK(*ptr4 == 1);

	ciel::unique_ptr<int> ptr5(ciel::move(ptr4));
	CHECK(*ptr5 == 1);
	CHECK(ptr4 == nullptr);

	ciel::unique_ptr<B, EmptyDeleter> ptr6;
	ciel::unique_ptr<A, EmptyDeleter> ptr7(ciel::move(ptr6));

	ciel::unique_ptr<int> ptr8 = ciel::make_unique<int>(0);
	ciel::unique_ptr<A> ptr9 = ciel::make_unique<A>();

	ciel::unique_ptr<int[]> ptr10;
	ciel::unique_ptr<int[]> ptr11(ciel::move(ptr10));
	ciel::unique_ptr<int[]> ptr12(new int[]{0, 1, 2, 3, 4});
	for (size_t i = 0; i < 5; ++i) {
		CHECK(ptr12[i] == i);
	}
	ciel::swap(ptr11, ptr12);
	for (size_t i = 0; i < 5; ++i) {
		CHECK(ptr11[i] == i);
	}
	ptr10 = ciel::make_unique<int[]>(5);
	for (size_t i = 0; i < 5; ++i) {
		CHECK(ptr10[i] == 0);
	}

	int* arr = new int[]{0, 1, 2, 3, 4};
	ciel::unique_ptr<int> ptr13(arr);
	ciel::unique_ptr<int> ptr14(arr + 3);
	CHECK(ptr13 < ptr14);
	CHECK(ptr13 <= ptr14);
	CHECK(ptr13 != ptr14);
	ptr14.release();

	ciel::unique_ptr<ciel::unique_ptr<int>> ptr15(new ciel::unique_ptr<int>(new int(5)));
	ciel::unique_ptr<ciel::unique_ptr<int>> ptr16(ciel::move(ptr15));

	std::cout << "All memory_tests finished.\n\n";
}

#endif //TINYSTLBYCIEL_TEST_CIEL_MEMORY_TEST_H_