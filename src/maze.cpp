#include "maze.hpp"
#include "cyclic_double_queue.hpp"
using namespace cs251;

void maze::initialize(const size_t dimX, const size_t dimY, const size_t dimZ, unsigned seed)
{
    m_dimX = dimX;
    m_dimY = dimY;
    m_dimZ = dimZ;

    delete[] m_map;
    m_map = new unsigned[m_dimX * m_dimY * m_dimZ];
    std::fill_n(m_map, m_dimX * m_dimY * m_dimZ, 0xFFFFFFFF);

    for (size_t z = 0; z < m_dimZ; ++z) {
        for (size_t y = 0; y < m_dimY; ++y) {
            for (size_t x = 0; x < m_dimX; ++x) {
                size_t index = get_index(x, y, z);
                Direction direction = get_next_direction(seed);
                m_map[index] &= ~static_cast<unsigned>(direction);
            }
        }
    }
}


bool maze::solve(const size_t startX, const size_t startY, const size_t startZ, const  size_t endX, const size_t endY, const size_t endZ)
{
	//TODO: Remove following line and add your implementation here.
    throw std::logic_error("maze::" + std::string(__FUNCTION__) + " not implemented");
}

std::string maze::print_walls(const size_t z) const
{
	//TODO: Remove following line and add your implementation here.
    throw std::logic_error("maze::" + std::string(__FUNCTION__) + " not implemented");
}

std::string maze::print_marks(const size_t z) const
{
	//TODO: Remove following line and add your implementation here.
    throw std::logic_error("maze::" + std::string(__FUNCTION__) + " not implemented");
}

void maze::get_dim(size_t& dimX, size_t& dimY, size_t& dimZ) const
{
	//TODO: Remove following line and add your implementation here.
    throw std::logic_error("maze::" + std::string(__FUNCTION__) + " not implemented");
}

Direction maze::get_next_direction(unsigned& seed)
{
	//Please do not modify this function! 
	//Any modification of this function may result in a zero for all grading cases.
	std::mt19937 gen(seed);
	seed = gen();
	return static_cast<Direction>(1 << seed % 6);
}

size_t maze::get_index(const size_t x, const size_t y, const size_t z) const
{
	//TODO: Remove following line and add your implementation here.
    throw std::logic_error("maze::" + std::string(__FUNCTION__) + " not implemented");
}


