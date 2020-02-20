#include <map>
#include <limits>
using namespace std;
class Key
{
	bool operator ==(const Key& k) {
		return false;
	}
	bool operator >(const Key& k) {
		return false;
	}
	Key operator +(const Key& k) {
		return Key();
	}
	Key operator -(const Key& k) {
		return Key();
	}
	Key operator /(const Key& k) {
		return Key();
	}
	Key operator *(const Key& k) {
		return Key();
	}
public:
	int key;
	bool operator<(const Key& k) {
		return this->key < k.key;
	}
};
class Value
{
	int value;
	bool operator >(const Value& k) {
		return false;
	}
	Value operator +(const Value& k) {
		return Value();
	}
	Value operator -(const Value& k) {
		return Value();
	}
	Value operator /(const Value& k) {
		return Value();
	}
	Value operator *(const Value& k) {
		return Value();
	}
public:
	Value() {
	}
	Value(int val) {
		this->value = val;
	}
	bool operator <(const Value& k) {
		return this->value < k.value;
	}
};
bool operator<(const Key& t1, const Key& t2)
{
	return (t1.key < t2.key);
}
template<typename K, typename V>
class interval_map {
	std::map<K, V> m_map;
public:
	// constructor associates whole range of K with val by inserting (K_min, val)
	// into the map
	interval_map(V const& val) {
		m_map.insert(m_map.end(), std::make_pair(std::numeric_limits<K>::lowest(), val));
	}
	// Assign value val to interval [keyBegin, keyEnd).
	// Overwrite previous values in this interval.
	// Conforming to the C++ Standard Library conventions, the interval
	// includes keyBegin, but excludes keyEnd.
	// If !( keyBegin < keyEnd ), this designates an empty interval,
	// and assign must do nothing.
	void assign(K const& keyBegin, K const& keyEnd, V const& val) {
		// Insert keyBegin, but if inserting keyBegin violates Canonicity,
		// delete keyBegin
		auto lower = m_map.lower_bound(keyBegin);
		if (val == (--lower)->second)
			m_map.erase(lower);
		else
			m_map.insert(std::make_pair(keyBegin, val));
		// Now we take care of the keyEnd part
		// 1. Delete all the keys that are in the range (keyBegin, keyEnd)
		auto start = m_map.upper_bound(keyBegin);
		auto end = --m_map.lower_bound(keyEnd);
		// Store value of the last interval before keyEnd
		int prev_val = end->second;
		m_map.erase(start, end);
		auto X2 = m_map.lower_bound(keyEnd);
		// To check if X2 is point to same key as keyEnd
		// if (X2->first == keyEnd){
		// }
	}
	// look-up of the value associated with key
	V const& operator[](K const& key) const {
		return (--m_map.upper_bound(key))->second;
	}
};
// Many solutions we receive are incorrect. Consider using a randomized test
// to discover the cases that your implementation does not handle correctly.
// We recommend to implement a test function that tests the functionality of
// the interval_map, for example using a map of unsigned int intervals to char.
int main(int argc, char const* argv[])
{
	interval_map<Key, Value> IMap(Value(5));
	return 0;
}