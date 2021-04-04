#pragma once

#include "list.h"
#include "../structure_iterator.h"
#include "../ds_routines.h"

namespace structures
{

	/// <summary> Prvok jednostranne zretazeneho zoznamu. </summary>
	/// <typeparam name = "T"> Typ dat ukladanych v prvku. </typepram>
	template<typename T>
	class CyclicListItem : public DataItem<T>
	{
	public:
		/// <summary> Konstruktor. </summary>
		/// <param name = "data"> Data, ktore uchovava. </param>
		CyclicListItem(T data);

		/// <summary> Kopirovaci konstruktor. </summary>
		/// <param name = "other"> Prvok jednstranne zretazeneho zoznamu, z ktoreho sa prevezmu vlastnosti.. </param>
		CyclicListItem(const CyclicListItem<T>& other);

		/// <summary> Destruktor. </summary>
		~CyclicListItem();

		/// <summary> Getter nasledujuceho prvku zretazeneho zoznamu. </summary>
		/// <returns> Nasledujuci prvok zretazeneho zoznamu. </returns>
		CyclicListItem<T>* getNext();
		CyclicListItem<T>* getPrev();

		/// <summary> Setter nasledujuceho prvku zretazeneho zoznamu. </summary>
		/// <param name´= "next"> Novy nasledujuci prvok zretazeneho zoznamu. </param>
		void setNext(CyclicListItem<T>* next);
		void setPrev(CyclicListItem<T>* prev);
	private:
		/// <summary> Nasledujuci prvok zretazeneho zoznamu. </summary>
		CyclicListItem<T>* next_;
		CyclicListItem<T>* prev_;
	};

	/// <summary> Jednostranne zretazeny zoznam. </summary>
	/// <typeparam name = "T"> Typ dat ukladanych v zozname. </typepram>
	template<typename T>
	class CyclicList : public List<T>
	{
	public:
		/// <summary> Konstruktor. </summary>
		CyclicList();

		/// <summary> Kopirovaci konstruktor. </summary>
		/// <param name = "other"> LinkedList, z ktoreho sa prevezmu vlastnosti. </param>
		CyclicList(const CyclicList<T>& other);

		/// <summary> Destruktor. </summary>
		~CyclicList();

		/// <summary> Operacia klonovania. Vytvori a vrati duplikat zoznamu. </summary>
		/// <returns> Ukazovatel na klon struktury. </returns>
		Structure* clone() const override;

		/// <summary> Vrati pocet prvkov v zozname. </summary>
		/// <returns> Pocet prvkov v zozname. </returns>
		size_t size() const override;

		/// <summary> Operator priradenia. </summary>
		/// <param name = "other"> Zoznam, z ktoreho ma prebrat vlastnosti. </param>
		/// <returns> Adresa, na ktorej sa tento zoznam nachadza po priradeni. </returns>
		List<T>& operator=(const List<T>& other) override;

		/// <summary> Operator priradenia. </summary>
		/// <param name = "other"> Zoznam, z ktoreho ma prebrat vlastnosti. </param>
		/// <returns> Adresa, na ktorej sa tento zoznam nachadza po priradeni. </returns>
		CyclicList<T>& operator=(const CyclicList<T>& other);

		/// <summary> Vrati adresou prvok na indexe. </summary>
		/// <param name = "index"> Index prvku. </param>
		/// <returns> Adresa prvku na danom indexe. </returns>
		/// <exception cref="std::out_of_range"> Vyhodena, ak index nepatri do zoznamu. </exception>  
		T& operator[](const int index) override;

		/// <summary> Vrati hodnotou prvok na indexe. </summary>
		/// <param name = "index"> Index prvku. </param>
		/// <returns> Hodnota prvku na danom indexe. </returns>
		/// <exception cref="std::out_of_range"> Vyhodena, ak index nepatri do zoznamu. </exception>  
		const T operator[](const int index) const override;

		/// <summary> Prida prvok do zoznamu. </summary>
		/// <param name = "data"> Pridavany prvok. </param>
		void add(const T& data) override;

		/// <summary> Vlozi prvok do zoznamu na dany index. </summary>
		/// <param name = "data"> Pridavany prvok. </param>
		/// <param name = "index"> Index prvku. </param>
		/// <exception cref="std::out_of_range"> Vyhodena, ak index nepatri do zoznamu. </exception>  
		/// <remarks> Ak je ako index zadana hodnota poctu prvkov (teda prvy neplatny index), metoda insert sa sprava ako metoda add. </remarks>
		void insert(const T& data, const int index) override;

		/// <summary> Odstrani prvy vyskyt prvku zo zoznamu. </summary>
		/// <param name = "data"> Odstranovany prvok. </param>
		/// <returns> true, ak sa podarilo prvok zo zoznamu odobrat, false inak. </returns>
		bool tryRemove(const T& data) override;

		/// <summary> Odstrani zo zoznamu prvok na danom indexe. </summary>
		/// <param name = "index"> Index prvku. </param>
		/// <returns> Odstraneny prvok. </returns>
		/// <exception cref="std::out_of_range"> Vyhodena, ak index nepatri do zoznamu. </exception>  
		T removeAt(const int index) override;

		/// <summary> Vrati index prveho vyskytu prvku v zozname. </summary>
		/// <param name = "data"> Prvok, ktoreho index sa hlada. </param>
		/// <returns> Index prveho vyskytu prvku v zozname, ak sa prvok v zozname nenachadza, vrati -1. </returns>
		int getIndexOf(const T& data) override;

		/// <summary> Vymaze zoznam. </summary>
		void clear() override;

		/// <summary> Vrati skutocny iterator na zaciatok struktury </summary>
		/// <returns> Iterator na zaciatok struktury. </returns>
		/// <remarks> Zabezpecuje polymorfizmus. </remarks>
		Iterator<T>* getBeginIterator() const override;

		/// <summary> Vrati skutocny iterator na koniec struktury </summary>
		/// <returns> Iterator na koniec struktury. </returns>
		/// <remarks> Zabezpecuje polymorfizmus. </remarks>
		Iterator<T>* getEndIterator() const override;

	private:
		/// <summary> Pocet prvkov v zozname. </summary>
		size_t size_;
		/// <summary> Prvy prvok zoznamu. </summary>
		CyclicListItem<T>* first_;
		/// <summary> Posledny prvok zoznamu. </summary>
		CyclicListItem<T>* last_;
		CyclicListItem<T>* prev_;
	private:
		/// <summary> Vrati prvok zoznamu na danom indexe. </summary>
		/// <param name = "index"> Pozadovany index. </summary>
		/// <returns> Prvok zoznamu na danom indexe. </param>
		/// <exception cref="std::out_of_range"> Vyhodena, ak index nepatri do zoznamu. </exception>  
		CyclicListItem<T>* getItemAtIndex(int index) const;
	private:
		/// <summary> Iterator pre LinkedList. </summary>
		class CyclicListIterator : public Iterator<T>
		{
		public:
			/// <summary> Konstruktor. </summary>
			/// <param name = "position"> Pozicia v zretazenom zozname, na ktorej zacina. </param>
			CyclicListIterator(CyclicListItem<T>* position);

			/// <summary> Destruktor. </summary>
			~CyclicListIterator();

			/// <summary> Operator priradenia. Priradi do seba hodnotu druheho iteratora. </summary>
			/// <param name = "other"> Druhy iterator. </param>
			/// <returns> Vrati seba po priradeni. </returns>
			Iterator<T>& operator= (const Iterator<T>& other) override;

			/// <summary> Porovna sa s druhym iteratorom na nerovnost. </summary>
			/// <param name = "other"> Druhy iterator. </param>
			/// <returns> True, ak sa iteratory nerovnaju, false inak. </returns>
			bool operator!=(const Iterator<T>& other) override;

			/// <summary> Vrati data, na ktore aktualne ukazuje iterator. </summary>
			/// <returns> Data, na ktore aktualne ukazuje iterator. </returns>
			const T operator*() override;

			/// <summary> Posunie iterator na dalsi prvok v strukture. </summary>
			/// <returns> Iterator na dalsi prvok v strukture. </returns>
			/// <remarks> Zvycajne vrati seba. Ak vrati iny iterator, povodny bude automaticky zruseny. </remarks>
			Iterator<T>& operator++() override;
		private:
			/// <summary> Aktualna pozicia v zozname. </summary>
			CyclicListItem<T>* position_;
		};
	};


	
	template<typename T>
	inline CyclicListItem<T>::CyclicListItem(T data):
		DataItem<T>(data),
		prev_(nullptr),
		next_(nullptr)
	{
	}

	template<typename T>
	inline CyclicListItem<T>::CyclicListItem(const CyclicListItem<T>& other):
		DataItem<T>(other),
		prev_(other.prev_),
		next_(other.next_)
	{
	}

	template<typename T>
	inline CyclicListItem<T>::~CyclicListItem()
	{
		prev_ = nullptr;
		next_ = nullptr;
	}

	template<typename T>
	inline CyclicListItem<T>* CyclicListItem<T>::getNext()
	{
		return next_;
	}

	template<typename T>
	inline CyclicListItem<T>* CyclicListItem<T>::getPrev()
	{
		return prev_;
	}

	template<typename T>
	inline void CyclicListItem<T>::setNext(CyclicListItem<T>* next)
	{
		next_ = next;
	}

	template<typename T>
	inline void CyclicListItem<T>::setPrev(CyclicListItem<T>* prev)
	{
		prev_ = prev;
	}

	template<typename T>
	inline CyclicList<T>::CyclicList():
		List(),
		size_(0),
		first_(nullptr),
		prev_(nullptr),
		last_(nullptr)
	{
	}

	template<typename T>
	inline CyclicList<T>::CyclicList(const CyclicList<T>& other):
		CyclicList()
	{
		*this = other;
	}

	template<typename T>
	inline CyclicList<T>::~CyclicList()
	{
		clear();
	}

	template<typename T>
	inline Structure* CyclicList<T>::clone() const
	{
		return new CyclicList<T>(*this);
	}

	template<typename T>
	inline size_t CyclicList<T>::size() const
	{
		return size_;
	}

	template<typename T>
	inline List<T>& CyclicList<T>::operator=(const List<T>& other)
	{
		if (this != &other)
		{
			*this = dynamic_cast<const CyclicList<T>&>(other);
		}
		return *this;
	}

	template<typename T>
	inline CyclicList<T>& CyclicList<T>::operator=(const CyclicList<T>& other)
	{
		if (this != &other)
		{
			clear();
			//pre takyto foreach musime mat vytvorene iteratory
			for (T data : other)
			{
				add(data);
			}

		}
		return *this;
		/*
		if (this != &other)
		{
			clear();
			CyclicListItem<T>* item = dynamic_cast<CyclicListItem<T>*>(other.first_);
			while (item != nullptr)
			{
				add(item->accessData());
				item = dynamic_cast<CyclicListItem<T>*>(item->getNext());
			}

		}
		return *this;
		*/
	}

	template<typename T>
	inline T& CyclicList<T>::operator[](const int index)
	{
		CyclicListItem<T>* item = getItemAtIndex(index);
		return item->accessData();
	}

	template<typename T>
	inline const T CyclicList<T>::operator[](const int index) const
	{
		CyclicListItem<T>* item = getItemAtIndex(index);
		return item->accessData();
	}

	template<typename T>
	inline void CyclicList<T>::add(const T& data)
	{
		CyclicListItem<T>* newItem = new CyclicListItem<T>(data);
		if (size_ == 0)
		{
			first_ = newItem;
			last_ = newItem;
		}
		else
		{
			last_->setNext(newItem);
			newItem->setNext(first_);
			first_->setPrev(newItem);
			newItem->setPrev(last_);
			last_ = newItem;
		}
		size_++;
	}

	template<typename T>
	inline void CyclicList<T>::insert(const T& data, const int index)
	{
		if (index == static_cast<int>(size_))
		{
			add(data);
		}
		else
		{
			DSRoutines::rangeCheckExcept(index, size_, "Invalid index in CyclicList!");
			CyclicListItem<T>* newItem = new CyclicListItem<T>(data);
			if (index == 0)
			{
				last_->setNext(newItem);
				newItem->setPrev(last_);
				first_->setPrev(newItem);
				newItem->setNext(first_);
				first_ = newItem;
			}
			else
			{
				CyclicListItem<T>* prevItem = getItemAtIndex(index - 1);
				newItem->setPrev(prevItem);
				newItem->setNext(prevItem->getNext());
				prevItem->setNext(newItem);
				newItem->getNext()->setPrev(newItem);
			}
			size_++;
		}
	}

	template<typename T>
	inline bool CyclicList<T>::tryRemove(const T& data)
	{
		return false;
	}

	template<typename T>
	inline T CyclicList<T>::removeAt(const int index)
	{
		DSRoutines::rangeCheckExcept(index, size_, "Invalid index in CyclicList!");
		/*CyclicListItem<T>* delItem;
		if (size_ == 1) //if(first_ == last_)
		{
			delItem = first_;
			first_ = nullptr;
			last_ = nullptr;
		}
		else
		{
			if (index == 0)
			{
				delItem = first_;
				first_ = first_->getNext();
			}
			else
			{
				CyclicListItem<T>* prevItem = getItemAtIndex(index - 1);
				delItem = prevItem->getNext();
				prevItem->setNext(delItem->getNext());
				if (last_ == delItem)
				{
					last_ = prevItem;
				}
			}
		}*/

		CyclicListItem<T>* delItem;
		if (index == 0)
		{
			delItem = first_;
			if (size_ == 1)
			{
				first_ = nullptr;
				last_ = nullptr;
			}
			else
			{
				first_ = first_->getNext();
				last_->setNext(first_);
				first_->setPrev(last_);
			}
		}
		else
		{
			CyclicListItem<T>* prevItem = getItemAtIndex(index - 1);
			delItem = prevItem->getNext();
			prevItem->setNext(delItem->getNext());
			prevItem->getNext()->setPrev(prevItem);
			if (last_ == delItem)
			{
				last_ = prevItem;
			}
		}

		T result = delItem->accessData();
		delete delItem;
		size_--;
		return result;
	}

	template<typename T>
	inline int CyclicList<T>::getIndexOf(const T& data)
	{
		CyclicListItem<T>* result = first_;
		int index = 0;
		while (result != last_)
		{
			if (result->accessData() == data)
			{
				return index;
			}
			index++;
			result = result->getNext();
		}
		return -1;
	}

	template<typename T>
	inline void CyclicList<T>::clear()
	{
		if (size_ != 0)
		{
			CyclicListItem<T>* delItem = first_;
			while (delItem != nullptr)
			{
				first_ = delItem->getNext();
				delete delItem;
				delItem = first_;
			}
			first_ = nullptr;
			last_ = nullptr;
			size_ = 0;
		}
	}

	template<typename T>
	inline Iterator<T>* CyclicList<T>::getBeginIterator() const
	{
		return new CyclicListIterator(first_);
	}

	template<typename T>
	inline Iterator<T>* CyclicList<T>::getEndIterator() const
	{
		return new CyclicListIterator(nullptr);
	}

	template<typename T>
	inline CyclicListItem<T>* CyclicList<T>::getItemAtIndex(int index) const
	{
		DSRoutines::rangeCheckExcept(index, size_, "Invalid index in CyclicList!");
		if (index < static_cast<int>(size_ / 2))
		{
			CyclicListItem<T>* result = first_;
			for (int i = 0; i < index; i++)
			{
				result = result->getNext();
			}
			return result;
		}
		else
		{
			CyclicListItem<T>* result = last_;
			for (int i = static_cast<int>(size_) - 1; i > index; i--)
			{
				result = result->getPrev();
			}
			return result;
		}
	}

	template<typename T>
	inline CyclicList<T>::CyclicListIterator::CyclicListIterator(CyclicListItem<T>* position)
	{
	}

	template<typename T>
	inline CyclicList<T>::CyclicListIterator::~CyclicListIterator()
	{
		position_ = nullptr;
	}

	template<typename T>
	inline Iterator<T>& CyclicList<T>::CyclicListIterator::operator=(const Iterator<T>& other)
	{
		position_ = dynamic_cast<const CyclicListIterator&>(other).position_;
		return *this;
	}

	template<typename T>
	inline bool CyclicList<T>::CyclicListIterator::operator!=(const Iterator<T>& other)
	{
		return position_ != dynamic_cast<const CyclicListIterator&>(other).position_;
	}

	template<typename T>
	inline const T CyclicList<T>::CyclicListIterator::operator*()
	{
		return position_->accessData();
	}

	template<typename T>
	inline Iterator<T>& CyclicList<T>::CyclicListIterator::operator++()
	{
		position_ = position_->getNext();
		return *this;
	}

}