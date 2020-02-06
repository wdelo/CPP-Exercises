#include "Dictionary.h"

template<class T>
Dictionary<T>::Dictionary() {

}

template<class T>
Dictionary<T>::~Dictionary() {

}

template<class T>
void Dictionary<T>::add(std::string _string, T _value) {
	KeyValuePair kvpo;

	kvpo.setValue(_value);
	kvpo.setString(_string);

	int index = hashASCII(kvpo.getString());

	hashTable[index].pushBack(kvpo);
}

template<class T>
void Dictionary<T>::remove(std::string _string) {
	checkWord(_string);

	int index = hashASCII(_string);
	int bucketIndex;
	bool bFound = false;

	for (int i = 0; i < hashTable[index].length() && !bFound; i++) {
		if (_string.compare(hashTable[index][i].getString()) == 0) {
			bucketIndex = i;
			bFound = true;
		}
	}

	hashTable[index].remove(bucketIndex);
}

template<class T>
T Dictionary<T>::lookup(std::string _string) {
	checkWord(_string);

	int index = hashASCII(_string);
	bool bFound = false;
	T value;

	for (int i = 0; i < hashTable[index].length() && !bFound; i++) {
		if (_string.compare(hashTable[index][i].getString()) == 0) {
			value = hashTable[index][i].getValue();
			bFound = true;
		}
	}

	return value;
}

template<class T>
bool Dictionary<T>::contains(std::string _string) {

	bool bCheckBucket = false;
	bool bFoundWord = false;
	int index = hashASCII(_string);

	if (hashTable[index].length() == 0) {
		return bCheckBucket;
	}
	else {
		for (int i = 0; i < hashTable[index].length() && !bFoundWord; i++) {
			if (_string.compare(hashTable[index][i].getString()) == 0) {
				bFoundWord = true;
			}
		}
	}

	return bFoundWord;
}

template<class T>
int Dictionary<T>::hashASCII(std::string _string) {
	int hashVal = 0;

	for (unsigned int i = 0; i < _string.length(); i++) {
		hashVal += _string[i];
	}

	return hashVal % 31;
}

template<class T>
void Dictionary<T>::checkWord(std::string _string) {
	bool bCheckWord = contains(_string);
	if (!bCheckWord) {
		printf("Error: word not found\n");
		exit(00);                                      // throw exception?
	}
}