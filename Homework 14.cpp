#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Structure for Donut, Batter, and Topping
struct Batter {
    string id;
    string type;
};

struct Topping {
    string id;
    string type;
};

struct Donut {
    string id;
    string name;
    vector<Batter> batters;
    vector<Topping> toppings;
};

// Function to display options and return the selected ID
string displayOptions(const vector<Batter>& batters, const string& label) {
    for (const auto& batter : batters) {
        cout << batter.id << ": " << batter.type << endl;
    }
    string selected_id;
    cout << "Choose a " << label << " type: ";
    cin >> selected_id;
    return selected_id;
}

string displayOptions(const vector<Topping>& toppings, const string& label) {
    for (const auto& topping : toppings) {
        cout << topping.id << ": " << topping.type << endl;
    }
    string selected_id;
    cout << "Choose a " << label << " type: ";
    cin >> selected_id;
    return selected_id;
}

// Function to get the choice by ID from a vector of batters or toppings
string getChoiceById(const string& id, const vector<Batter>& batters) {
    for (const auto& batter : batters) {
        if (batter.id == id) {
            return batter.type;
        }
    }
    return "";
}

string getChoiceById(const string& id, const vector<Topping>& toppings) {
    for (const auto& topping : toppings) {
        if (topping.id == id) {
            return topping.type;
        }
    }
    return "";
}

// Main ordering system
void orderDonuts(const vector<Donut>& donuts) {
    // Display donut types
    cout << "Choose a donut type:\n";
    for (const auto& donut : donuts) {
        cout << donut.id << ": " << donut.name << endl;
    }

    string donut_choice_id;
    cout << "Choose a donut type: ";
    cin >> donut_choice_id;

    // Find the selected donut
    Donut selected_donut;
    for (const auto& donut : donuts) {
        if (donut.id == donut_choice_id) {
            selected_donut = donut;
            break;
        }
    }

    if (!selected_donut.id.empty()) {
        // Display batter options for the selected donut
        cout << "Choose a batter type for the " << selected_donut.name << " donut:\n";
        string batter_choice_id = displayOptions(selected_donut.batters, "batter");
        string selected_batter = getChoiceById(batter_choice_id, selected_donut.batters);

        if (!selected_batter.empty()) {
            // Display topping options for the selected batter
            cout << "Choose a topping type for the " << selected_batter << " batter:\n";
            string topping_choice_id = displayOptions(selected_donut.toppings, "topping");
            string selected_topping = getChoiceById(topping_choice_id, selected_donut.toppings);

            if (!selected_topping.empty()) {
                cout << "\nYou have ordered a " << selected_donut.name << " donut with "
                     << selected_batter << " batter and " << selected_topping << " topping.\n";
            } else {
                cout << "Invalid topping choice.\n";
            }
        } else {
            cout << "Invalid batter choice.\n";
        }
    } else {
        cout << "Invalid donut choice.\n";
    }
}

int main() {
    // Initialize the donut menu (sample data from the JSON)
    vector<Donut> donuts = {
        {
            "0001", "Cake",
            {
                {"1001", "Regular"},
                {"1002", "Chocolate"},
                {"1003", "Blueberry"},
                {"1004", "Devil's Food"}
            },
            {
                {"5001", "None"},
                {"5002", "Glazed"},
                {"5005", "Sugar"},
                {"5007", "Powdered Sugar"},
                {"5006", "Chocolate with Sprinkles"},
                {"5003", "Chocolate"},
                {"5004", "Maple"}
            }
        },
        {
            "0002", "Raised",
            {{"1001", "Regular"}},
            {
                {"5001", "None"},
                {"5002", "Glazed"},
                {"5005", "Sugar"},
                {"5003", "Chocolate"},
                {"5004", "Maple"}
            }
        },
        {
            "0003", "Old Fashioned",
            {
                {"1001", "Regular"},
                {"1002", "Chocolate"}
            },
            {
                {"5001", "None"},
                {"5002", "Glazed"},
                {"5003", "Chocolate"},
                {"5004", "Maple"}
            }
        }
    };

    // Start the donut ordering process
    orderDonuts(donuts);

    return 0;
}
