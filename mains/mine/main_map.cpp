#include <iostream>
#include <string>

#ifdef MINE
	#include "../../containers/map.hpp"
#else
	#include <map>
#endif

using namespace NAMESPACE;

#define CYAN "\033[0;36m"
#define MAGENTA "\033[0;35m"
#define YELLOW "\033[0;33m"
#define GREEN "\033[0;32m"
#define END_COLOR "\033[0m"

int main()
{

	//////////////// TEST MAP ////////////////////

	std::cout << std::endl << CYAN << "************* Test Map **************" << END_COLOR << std::endl << std::endl;

	std::cout << YELLOW << "  * Test 1: Constructors *  " << END_COLOR << std::endl;
	std::cout << std::endl;

	std::cout << "Test default constructor : ";
	map<std::string, int> default_;
	default_["K0"] = 10;
	default_["ok"] = 15;
	std::cout << GREEN << "Default constructor works!" << END_COLOR << std::endl << std::endl;

	std::cout << "Test range constructor : " << std::endl;
	map<std::string, int> range(default_.find("ok"), default_.end());
	std::cout << "range map print: { ";
	for (map<std::string, int>::iterator it = default_.begin(); it != default_.end(); it++)
		std::cout << it->first << " " << it->second << "; ";
	std::cout << "}" << std::endl;
	std::cout << "trying to find ok in map: find!" << std::endl;
	std::cout << GREEN << "Range constructor works!" << END_COLOR << std::endl << std::endl;
	
	std::cout << "Test copy constructor : ";
	map<std::string, int> copy(default_);
	std::cout << GREEN << "Copy constructor works!" << END_COLOR << std::endl;
	std::cout << std::endl;
	


	std::cout << YELLOW << "  * Test 2: Element Access *  " << END_COLOR << std::endl;
	std::cout << std::endl;


	std::cout << "Test at() : " << std::endl;
	map<char, int> m;
	m['d'] = 4;
	m['c'] = 99;
	m['e'] = 88;
	m['d'] = 3;
	m['e'];
	std::cout << std::endl;
	std::cout << "--- Create a new map ---" << std::endl;
	std::cout << std::endl;
	std::cout << "-> map print: { ";
	for (map<char, int>::iterator it = m.begin(); it != m.end(); it++)
		std::cout << it->first << " " << it->second << "; ";
	std::cout << std::endl;
	
	std::cout << std::endl;
	std::cout << "Try to access a non-existant element 'z': ";
	try {
		m.at('z');
	} catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << GREEN << "Return exception!" << END_COLOR << std::endl;
	std::cout << std::endl;
	
	std::cout << "Try to access a non-existant element 'z' in a new map copy: ";
	const map<char, int> mc(m);
	try {
		mc.at('z');
	} catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << GREEN << "Return exception!" << END_COLOR << std::endl;
	std::cout << std::endl;
	
	std::cout << "Try to access 'c' in map: ";
	try {
		m.at('c');
	} catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;
	std::cout << GREEN << "Doesn't Return exception because 'c' is in map!" << END_COLOR << std::endl;
	std::cout << std::endl;
	
	std::cout << "Test operator[] : " << std::endl;
	std::cout << std::endl;
	std::cout << "Display element map['c']: " << m['c'] << std::endl;
	std::cout << GREEN << "Operator[] works!" << END_COLOR << std::endl;
	std::cout << std::endl;


	std::cout << YELLOW << "  * Test 3: Capacity *  " << END_COLOR << std::endl;
	std::cout << std::endl;

	map<char, int> emp;
	std::cout << "Test if the empty map is empty(): " << emp.empty() << GREEN << " TRUE" << END_COLOR << std::endl;
	std::cout << "Test if the non empty map is empty(): " << m.empty() << GREEN << " FALSE" << END_COLOR << std::endl;
	std::cout << std::endl;

	


	map<char, int>::const_iterator cit = mc.find('c');
	std::cout << cit->first << " " << cit->second << std::endl;
	cit = mc.lower_bound('e');
	std::cout << cit->first << " " << cit->second << std::endl;
	pair<map<char, int>::const_iterator, map<char, int>::const_iterator> pc;
	pc = mc.equal_range('d');
	std::cout << "equal range: ";
	std::cout << pc.first->first << " " << pc.first->second << ", ";
	std::cout << pc.second->first << " " << pc.second->second << std::endl;

	m['q'] = 42;
	m['r'] = 55;
	m['d'] = 25;
	m['o'] = 10;
	m['w'] = 90;

	std::cout << std::boolalpha;
	pair<map<char, int>::iterator, bool> ret = m.insert(make_pair('h', 216));
	std::cout << "insert ret: " << ret.first->first << " " << ret.first->second << ", " << ret.second << std::endl;
	ret = m.insert(make_pair('h', 212));
	std::cout << "insert ret: " << ret.first->first << " " << ret.first->second << ", " << ret.second << std::endl;

	map<char, int>::iterator ret2 = m.insert(m.begin(), make_pair('w', 99));
	std::cout << "2nd insert ret: ";
	std::cout << ret2->first << " " << ret2->second << std::endl;
	map<char, int> m2(m);
	ret2 = m.insert(m2.begin(), make_pair('w', 99));
	std::cout << "2nd insert ret: ";
	std::cout << ret2->first << " " << ret2->second << std::endl;
	// Should segfault
	/*map<char, int>::iterator nil;
	ret2 = m.insert(nil, make_pair('w', 99));
	std::cout << "2nd insert ret: ";
	std::cout << ret2->first << " " << ret2->second << std::endl;*/

	for (map<char, int>::iterator it = m.begin(); it != m.end(); it++)
		std::cout << it->first << " " << it->second << std::endl;
	std::cout << std::endl;
	for (map<char, int>::const_iterator it = mc.begin(); it != mc.end(); it++)
		std::cout << it->first << " " << it->second << std::endl;

	std::cout << "m size: " << m.size() << std::endl;
	std::cout << "mc size: " << mc.size() << std::endl;

	std::cout << "Template tests" << std::endl;
	map<char, int> mt(m.begin(), m.end());
	mt.insert(mt.begin(), mt.end());
	for (map<char, int>::iterator it = mt.begin(); it != mt.end(); it++)
		std::cout << it->first << " " << it->second << ", ";
	std::cout << std::endl;
	return 0;
}
