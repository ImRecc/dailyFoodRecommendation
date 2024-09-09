#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// FoodInfors structure
struct FoodInfors 
{
    string name;
    int calories;
    int protein;
    int preference;
};

// UserInfors structure
struct UserInfors 
{
    string name;
    int dailyCalorieRequirement;
    int dailyProteinRequirement;
};

// Class for the recommendation logic
class FoodRecommender 
{
public:
    vector<FoodInfors> recommendFood(vector<FoodInfors>& foodList, int calorieTarget, string priority) {
        vector<FoodInfors> selectedFoods;

        // Sort foodList based on priority
        if (priority == "caloriesFirst") {
            sort(foodList.begin(), foodList.end(), [](FoodInfors& a, FoodInfors& b) {
                return a.calories > b.calories;
            });
        } else if (priority == "proteinFirst") {
            sort(foodList.begin(), foodList.end(), [](FoodInfors& a, FoodInfors& b) {
                return a.protein > b.protein;
            });
        } else if (priority == "preferenceFirst") {
            sort(foodList.begin(), foodList.end(), [](FoodInfors& a, FoodInfors& b) {
                return a.preference > b.preference;
            });
        }

        // Select foods based on calorie target
        int totalCalories = 0;
        for (auto& food : foodList) {
            if (totalCalories + food.calories <= calorieTarget) {
                selectedFoods.push_back(food);
                totalCalories += food.calories;
            }
        }

        return selectedFoods;
    }
};

// Test the recommender system
int main() {
    vector<FoodInfors> foodList = {
        {"Chicken Salad", 300, 30, 4},
        {"Beef Steak", 500, 40, 5},
        {"Vegetable Soup", 150, 5, 3},
        {"Pasta", 400, 15, 4}
    };

    UserInfors user = {"John Doe", 2000, 100};  // Example user

    FoodRecommender recommender;

    vector<FoodInfors> recommendations = recommender.recommendFood(foodList, 600, "caloriesFirst");

    cout << "Recommended Foods:" << endl;
    for (const auto& food : recommendations) {
        cout << food.name << " - " << food.calories << " calories" << endl;
    }

    return 0;
}
