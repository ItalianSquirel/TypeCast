#include <string>;
//represents a species of fish
struct Fish {
	std::string name = "unnamed fish";
	float minWeight = 0.5f;
	float maxWeight = 25;
	float minLength = 4;
	float maxLength = 64;
};