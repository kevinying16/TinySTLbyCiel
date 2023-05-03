#ifndef TINYSTLBYCIEL_INCLUDE_CIEL_EXCEPTION_H_
#define TINYSTLBYCIEL_INCLUDE_CIEL_EXCEPTION_H_

namespace ciel {

	class exception {
	public:
		exception() noexcept {}

		exception(const exception& other) noexcept = default;

		virtual ~exception() noexcept;

		exception& operator=(const exception& other) noexcept;

		virtual const char* what() const noexcept;

	};    //class exception

}   //namespace ciel

#endif //TINYSTLBYCIEL_INCLUDE_CIEL_EXCEPTION_H_