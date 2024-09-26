// @algorithm @lc id=100228 lang=cpp 
// @title animal-shelter-lcci
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class AnimalShelf {
private:
    queue<int> cat;
    queue<int> dog;
public:
    AnimalShelf() {

    }
    
    void enqueue(vector<int> animal) {
        if (animal[1] == 0) { 
            cat.push(animal[0]);
        } else { 
            dog.push(animal[0]);
        }
    }
    
    vector<int> dequeueAny() {
        if (cat.empty()) {
            return dequeueDog();
        }
        if (dog.empty()) {
            return dequeueCat();
        }
        if (cat.front() < dog.front()) {
            return dequeueCat();
        } else {
            return dequeueDog();
        }
    }
    
    vector<int> dequeueDog() {
        if (dog.empty()) {
            return {-1, -1};
        }
        int id = dog.front();
        dog.pop();
        return {id, 1};
    }
    
    vector<int> dequeueCat() {
        if (cat.empty()) {
            return {-1, -1};
        }
        int id = cat.front();
        cat.pop();
        return {id, 0};
    }
};
