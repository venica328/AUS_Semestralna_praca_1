#pragma once

#include "structures/structure.h"
#include "structures/structure_iterator.h"
#include "structures/ds_structure_types.h"

namespace structures
{
	template<typename T>
	class Matica
	{
	public:
		virtual Structure* clone() const = 0;

		virtual size_t size() const = 0;

		virtual T get(int riadok, int stlpec) = 0;
		virtual T set(int riadok, int stlpec, T data) = 0;
		virtual T getPocetRiadkov() const = 0;
		virtual size_t getPocetStlpcov() const = 0;


	protected:
		Matica(size_t riadky, size_t stlpce);
		size_t riadky;
		size_t stlpce;
	};

	template<typename T>
	inline Matica<T>::Matica(size_t riadky, size_t stlpce) :
		riadky(riadky), stlpce(stlpce)
	{
	}

}