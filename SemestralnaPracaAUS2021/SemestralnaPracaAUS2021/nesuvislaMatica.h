#pragma once

#include "structures/structure.h"
#include "structures/vector/vector.h"
#include "structures/ds_routines.h"
#include "matica.h"
#include "structures/array/array.h"

namespace structures
{
	template<typename T>
	class NesuvislaMatica : public Matica<T>
	{
	public:
		NesuvislaMatica(size_t riadky, size_t stlpce);
		virtual ~NesuvislaMatica();
		virtual T get(int riadok, int stlpec);
		virtual T set(int riadok, int stlpec, T data);
		virtual T getPocetRiadkov() const;
		virtual size_t getPocetStlpcov() const;
		Structure* clone() const override;
		size_t size() const override;
		

	private:
		int mapFunction(int riadok, int stlpec) const;
		int pocetRiadkov = 0;
		int pocetStlpcov = 0;
		Array<Array<T>*>* pole;
	};
	template<typename T>
	inline NesuvislaMatica<T>::NesuvislaMatica(size_t riadky, size_t stlpce):
	Matica<T>(riadky,stlpce),
	pole(new Array<Array<T>*>(riadky))
	{
		for (int i = 0; i < getPocetRiadkov(); i++)
		{
			(*pole)[i] = new Array<T>(stlpce);

		}

	}
	template<typename T>
	inline NesuvislaMatica<T>::~NesuvislaMatica()
	{
		Matica<T>::~Matica();
		for (int i = 0; i < getPocetRiadkov(); i++)
		{
			delete (*pole)[i];
		}
		delete pole;
	}
	template<typename T>
	inline T NesuvislaMatica<T>::get(int riadok, int stlpec)
	{
		return (*((*pole)[riadok]))[stlpec];
		//return (*((*pole)[riadok]))[mapFunction(riadok, stlpec)];
	}
	template<typename T>
	inline T NesuvislaMatica<T>::set(int riadok, int stlpec, T data)
	{
		(*((*pole)[riadok]))[stlpec] = data;
		//data = (*((*pole)[riadok]))[mapFunction(riadok, stlpec)];
		return data;
	}
	template<typename T>
	inline T NesuvislaMatica<T>::getPocetRiadkov() const
	{
		return riadky;
	}
	template<typename T>
	inline size_t NesuvislaMatica<T>::getPocetStlpcov() const
	{
		return stlpce;
	}
	template<typename T>
	inline Structure* NesuvislaMatica<T>::clone() const
	{
		return NULL;
	}
	template<typename T>
	inline size_t NesuvislaMatica<T>::size() const
	{
		return size_t();
	}
	template<typename T>
	inline int NesuvislaMatica<T>::mapFunction(int riadok, int stlpec) const
	{
		return (riadok * this->stlpce) + stlpec;
	}
}
