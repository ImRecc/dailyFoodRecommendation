#include <iostream>
#include <vector>
#include <string>

using namespace std;
/*to avoid repeatadlly std::string
and vector lib just allow us using dynamic array, resize dymanically
*/

// Define the structure for a Food item
struct FoodInfors {
    string name;
    int calories;
    int protein;
    int preference;
};

// Define the structure for User profile
struct UserInfors 
{
    int dailyCalorieRequirement;
    int dailyProteinRequirement;
    int mealCalories[3]; // This will store calorie requirements for 3 meals (breakfast, lunch, dinner)

    UserInfors(int dailyCalories, int dailyProteins) 
    {
        dailyCalorieRequirement = dailyCalories;
        dailyProteinRequirement = dailyProteins;
        mealCalories[0] = dailyCalories * 0.3;  // 30% for breakfast
        mealCalories[1] = dailyCalories * 0.4;  // 40% for lunch
        mealCalories[2] = dailyCalories * 0.3;  // 30% for dinner
    }
    //this just a constructor initializer, in case you forgot;
};

class FoodRecommender 
{
public:
    // Function to manually input food data
    void addFood(string name, int calories, int protein, int preference) 
    {
        FoodInfors food = { name, calories, protein, preference };
        foodList.push_back(food); // Add food to the list
    }
    // Function to display all foods (for testing purposes)
    void displayFoods() 
    {
        for (auto& food : foodList) 
        {
            cout << "Name: " << food.name << ", Calories: " << food.calories
                << ", Protein: " << food.protein << ", Preference: " << food.preference << endl;
        }
    }

private:
    vector<FoodInfors> foodList; // Store the list of foods
};

int main() 
{
    FoodRecommender recommender;

    // Manually add food items
    recommender.addFood("Chicken Salad", 300, 30, 4);
    recommender.addFood("Beef Steak", 500, 40, 5);
    recommender.addFood("Vegetable Soup", 150, 5, 3);

    // Display all added foods
    recommender.displayFoods();

    return 0;
}
