#pragma once

#include "structures/structure.h"
#include "structures/vector/vector.h"
#include "structures/ds_routines.h"
#include "matica.h"
#include "structures/array/array.h"

namespace structures
{
	template<typename T>
	class SuvislaMatica : public Matica<T>
	{
	public:
		SuvislaMatica(size_t riadky, size_t stlpce);
		virtual ~SuvislaMatica();
		virtual T get(int riadok, int stlpec);
		virtual T set(int riadok, int stlpec, T data);
		virtual T getPocetRiadkov() const;
		virtual size_t getPocetStlpcov() const;
		Structure* clone() const override;
		size_t size() const override;
		Array<T>* pole;

	private:
		int mapFunction(int riadok, int stlpec) const;
		int pocetRiadkov = 0;
		int pocetStlpcov = 0;
	};

	
	template<typename T>
	inline SuvislaMatica<T>::SuvislaMatica(size_t riadky, size_t stlpce):Matica<T>(riadky,stlpce)
	{
		pole = new Array<T>(riadky * stlpce);
	}
	template<typename T>
	inline SuvislaMatica<T>::~SuvislaMatica()
	{
		delete pole;
		pole = nullptr;
	}
	template<typename T>
	inline T SuvislaMatica<T>::get(int riadok, int stlpec)
	{
		return (*pole)[mapFunction(riadok,stlpec)];
	}
	template<typename T>
	inline T SuvislaMatica<T>::set(int riadok, int stlpec, T data)
	{
		(*pole)[mapFunction(riadok, stlpec)] = data;
		return data;
	}
	template<typename T>
	inline T SuvislaMatica<T>::getPocetRiadkov() const
	{
		return riadky;
	}

	template<typename T>
	inline size_t SuvislaMatica<T>::getPocetStlpcov() const
	{
		return stlpce;
	}

	template<typename T>
	inline Structure* SuvislaMatica<T>::clone() const
	{
		return NULL;
	}

	template<typename T>
	inline size_t SuvislaMatica<T>::size() const
	{
		return size_t();
	}

	template<typename T>
	inline int SuvislaMatica<T>::mapFunction(int riadok, int stlpec) const
	{
		return (riadok * this->stlpce) + stlpec;
		//return (riadok * pocetStlpcov * stlpec) * sizeof(T);
	}

}

