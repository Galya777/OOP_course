#pragma once
#include <iostream>

template <typename Elem_t>
class Vector
{
public:
	Vector(size_t capacity = 0);
	Vector(const Vector<Elem_t>& other);
	Vector<Elem_t>& operator=(const Vector<Elem_t>& other);
	~Vector();

	inline size_t size() const { return m_size; }
	inline size_t capacity() const { return m_capacity; }
	inline bool empty() const { return m_size == 0; }
	Elem_t& at(size_t index);
	const Elem_t& at(size_t index) const;
	void push_back(const Elem_t& element);
	void pop_back();
	void insert(size_t index, const Elem_t& element);
	void erase(size_t index);
	void reserve(size_t capacity);

	template <typename Pred>
	void sort(Pred comparator);

	Elem_t& operator[](size_t index);
	const Elem_t& operator[](size_t index) const;
	Vector<Elem_t>& operator+=(const Elem_t& elem);
	Vector<Elem_t>& operator+=(const Vector<Elem_t>& other);

private:
	void copy(const Vector<Elem_t>& other);
	void clear();

	static const size_t DEFAULT_CAPACITY;

	static const size_t RESIZE_FACTOR;
	size_t m_size;
	size_t m_capacity;
	Elem_t* m_arr;
};

template <typename Elem_t>
std::ostream& operator<<(std::ostream& out, const Vector<Elem_t>& obj);

#include "Vector.ipp"


