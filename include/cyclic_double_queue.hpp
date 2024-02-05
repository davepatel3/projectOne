#pragma once
#include "cstring"
#include "sstream"
#include "string"
#include <iostream>
namespace cs251
{
	template<typename T>
	class cyclic_double_queue
	{
	public:
		/**
		 * \brief The constructor with settings.
		 * \param initialCapacity Preset initial capacity of the array.
		 * \param increaseFactor Preset increase factor for expanding the array.
		 * \param decreaseFactor Preset decrease factor for shrinking the array.
		 */
		cyclic_double_queue(size_t initialCapacity = 7, size_t increaseFactor = 2, size_t decreaseFactor = 2);
		/**
		 * \brief The default destructor. You should make sure no memory leaks happens after the queue is destroyed.
		 */
		~cyclic_double_queue();
		/**
		 * \brief Push the item at the front of the queue.
		 * \param item The item to be added.
		 */
		void enqueue_front(const T& item);
		/**
		 * \brief Push the item at the back of the queue.
		 * \param item The item to be added.
		 */
        bool full(const T* items) const;
        /**
         * \brief Checks if the passed array is full or not
         * \param items The array to be checked 
         */     
		void enqueue_back(const T& item);
		/**
		 * \brief Returns the occupancy of the queue.
		 * \return Whether the queue is empty.
		 */
		bool empty() const;
		/**
		 * \brief Dequeue the element at the front of the queue.
		 * \return The item dequeued.
		 */
		T dequeue_front();
		/**
		 * \brief Dequeue the element at the back of the queue.
		 * \return The item dequeued.
		 */
		T dequeue_back();
		/**
		 * \brief Remove the item at the front of the queue, returns nothing.
		 */
		void pop_front();
		/**
		 * \brief Remove the item at the back of the queue, returns nothing.
		 */
		void pop_back();
		/**
		 * \brief Provide the access to the item at the front of the queue.
		 * \return The modifiable reference to the item.
		 */
		T& front();
		/**
		 * \brief Provide the access to the item at the back of the queue.
		 * \return The modifiable reference to the item.
		 */
		T& back();
		/**
		 * \brief Empty the queue, and resize the queue to initial capacity.
		 * \n !Note! You should set the size and the front index of the queue to 0 when this function is called!
		 */
		void clear();
		/**
		 * \brief Print the queue's current status according to the handout.
		 * \return The string represents the array. For format please refer to the handout.
		 */
		std::string print_status() const;
		/**
		 * \brief Returns the number of items currently in queue.
		 * \return The size of the queue.
		 */
		size_t get_size() const;
		/**
		 * \brief Returns the total capacity of the array.
		 * \return The capacity of the array.
		 */
		size_t get_capacity() const;
        /**
		 * \brief Returns the increase factor of the array when resizing.
		 * \return The increase factor.
		 */
        size_t get_increase_factor() const;
	private:
		//TODO: You may add private members/methods here.
		/**
		 * Item array, the underlying data structure for the queue
		 */
		T* m_data = nullptr;
		/**
		 * The front index of the queue within the array
		 */
		size_t m_frontIndex = 0;
        /**
         * The back index of the queue within the array
         */
        size_t m_backIndex = 0;
		/**
		 * The length of the array, including the empty slots.
		 */
		size_t m_capacity = 0;
		/**
		 * Keeps track of the size of the queue
		 */
		size_t m_size = 0;
		/**
		 * Factor by which the queue length must be increased 
		 */
		size_t m_increaseFactor = 0;
		/**
		 * Factor by which the queue length must be decreased
		 */
		size_t m_decreaseFactor = 0;
		/**
		 * The initial capacity of the queue, predefined as 7
		 */
		size_t m_initialCapacity = 0;
	};

	template <typename T>
	cyclic_double_queue<T>::cyclic_double_queue(const size_t initialCapacity, const size_t increaseFactor, size_t decreaseFactor)
	{
        m_data = new T[m_initialCapacity];
        this -> m_initialCapacity = initialCapacity;
        this -> m_increaseFactor = increaseFactor;
        this -> m_decreaseFactor = decreaseFactor;
        this -> m_capacity = m_initialCapacity;
	}

	template <typename T>
	cyclic_double_queue<T>::~cyclic_double_queue()
	{
	    delete[] m_data;
	}
    
    //template <typename T>
    //bool cyclic_double_queue<T>::full(const T* items) const {
        //if(int(sizeof(items) / sizeof(T)) == m_initialCapacity){
            //return true;
        //}
            //else{
            //return false;
        //}
    //}/

	template <typename T>
	void cyclic_double_queue<T>::enqueue_front(const T& item)
	{
        int new_array_capacity;
        if(m_size == m_capacity){
            new_array_capacity = m_capacity * m_increaseFactor;
            T* new_array = new T[new_array_capacity];
            for (int i = 0; i < m_size; ++i) {
                new_array[i] = m_data[(m_frontIndex + i) % m_capacity];
            }
            delete[] new_array;
            m_capacity = new_array_capacity;
            m_frontIndex = 0;
            m_data = new_array;
        }
        
	    else if (m_frontIndex == 0) {
            m_frontIndex = m_capacity - 1;
        } else {
            m_frontIndex -=1;
        }
        m_data[m_frontIndex] = item;
        m_size++;

    } 

	template <typename T>
	void cyclic_double_queue<T>::enqueue_back(const T& item)
	{
		//if(full(m_data)){
            //int diff = int(sizeof(m_data)/sizeof(T)) - m_frontIndex;
            //T* m_data_new = new T[get_capacity() * get_increase_factor()];
            //for(int i = m_frontIndex; i < int(sizeof(m_data)/sizeof(T)); i++){
                //m_data_new[i-m_frontIndex] = m_data[i];
            //}/
            //for(int i = m_backIndex-1; i>= 0; i--){
                //m_data_new[i + diff] = m_data[i];
            //}/
           // m_frontIndex = 0;
            //m_backIndex = int(sizeof(m_data)/sizeof(T)) + 1;
            //delete[] m_data;
            //m_data = m_data_new;
            //m_capacity *= m_increaseFactor;
            
            
            //start changes for back here 
            //m_data[m_backIndex] = item;
            //m_backIndex +=1; 
            
            //m_size +=1;
        //}/
	    //else if(m_backIndex == m_capacity - 1){
            //m_data[m_frontIndex] = item;
            //m_backIndex = 0;
            //m_size +=1;
        //}/
        //else {
            //m_backIndex+=1;
            //m_data[m_backIndex] = item;
            //m_size +=1;
	    //}/
	}

	template <typename T>
	T cyclic_double_queue<T>::dequeue_front()
	{
		//TODO: Remove following line and add your implementation here.
		throw std::logic_error("cyclic_double_queue::" + std::string(__FUNCTION__) + " not implemented");
	}

	template <typename T>
	T cyclic_double_queue<T>::dequeue_back()
	{
		//TODO: Remove following line and add your implementation here.
		throw std::logic_error("cyclic_double_queue::" + std::string(__FUNCTION__) + " not implemented");
	}

	template <typename T>
	void cyclic_double_queue<T>::pop_front()
	{
		//TODO: Remove following line and add your implementation here.
		throw std::logic_error("cyclic_double_queue::" + std::string(__FUNCTION__) + " not implemented");
	}

	template <typename T>
	void cyclic_double_queue<T>::pop_back()
	{
		//TODO: Remove following line and add your implementation here.
		throw std::logic_error("cyclic_double_queue::" + std::string(__FUNCTION__) + " not implemented");
	}

	template <typename T>
	bool cyclic_double_queue<T>::empty() const
	{
		//TODO: Remove following line and add your implementation here.
		throw std::logic_error("cyclic_double_queue::" + std::string(__FUNCTION__) + " not implemented");
	}

	template <typename T>
	T& cyclic_double_queue<T>::front()
	{
		//TODO: Remove following line and add your implementation here.
		throw std::logic_error("cyclic_double_queue::" + std::string(__FUNCTION__) + " not implemented");
	}

	template <typename T>
	T& cyclic_double_queue<T>::back()
	{
		//TODO: Remove following line and add your implementation here.
		throw std::logic_error("cyclic_double_queue::" + std::string(__FUNCTION__) + " not implemented");
	}

	template <typename T>
	void cyclic_double_queue<T>::clear()
	{
		//TODO: Remove following line and add your implementation here.
		throw std::logic_error("cyclic_double_queue::" + std::string(__FUNCTION__) + " not implemented");
	}

	template <typename T>
	std::string cyclic_double_queue<T>::print_status() const
	{
		//TODO: Remove following line and add your implementation here.
		throw std::logic_error("cyclic_double_queue::" + std::string(__FUNCTION__) + " not implemented");
	}

	template <typename T>
	size_t cyclic_double_queue<T>::get_size() const
	{
		//TODO: Remove following line and add your implementation here.
		throw std::logic_error("cyclic_double_queue::" + std::string(__FUNCTION__) + " not implemented");
	}

	template <typename T>
	size_t cyclic_double_queue<T>::get_capacity() const
	{
		return m_capacity;
	}
    
    template <typename T>
	size_t cyclic_double_queue<T>::get_increase_factor() const
	{
		return m_increaseFactor;
	}
    
    
}
