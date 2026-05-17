#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
using namespace std;

bool contains(vector<string> &symptoms, string target)
{
    return find(symptoms.begin(), symptoms.end(), target) != symptoms.end();
}

string diagnose(vector<string> &symptoms)
{
    if (contains(symptoms, "fever") && contains(symptoms, "cough") && contains(symptoms, "breathlessness"))
    {
        return "Possible Condition: COVID-19\n Advice: Get tested and isolated\n";
    }
    else if (contains(symptoms, "fever") && contains(symptoms, "headache") && contains(symptoms, "body pain"))
    {
        return "Possible Condition: Flu\nAdvice: Take rest and drink fluids.";
    }
    else if (contains(symptoms, "chest pain") && contains(symptoms, "breathlessness"))
    {
        return "Possible Condition: Heart Disease\nAdvice: Consult a cardiologist immediately.";
    }
    else if (contains(symptoms, "stomach pain") && contains(symptoms, "vomiting"))
    {
        return "Possible Condition: Food Poisoning\nAdvice: Stay hydrated and consult a doctor.";
    }
    else if (contains(symptoms, "frequent urination") && contains(symptoms, "increased thirst"))
    {
        return "Possible Condition: Diabetes\nAdvice: Check blood sugar level.";
    }
    else
    {
        return "Condition unclear\nAdvice: Please consult a doctor.";
    }
}

int main()
{
    string input;
    cout << "Medical Expert System" << endl;
    cout << "Enter symptoms separated by commas" << endl;
    getline(cin, input);
    transform(input.begin(), input.end(), input.begin(), ::tolower);
    vector<string> symptoms;
    stringstream ss(input);
    string segment;

    while (getline(ss, segment, ','))
    {
        symptoms.push_back(segment);
    }
    string result = diagnose(symptoms);
    cout << "\n Diagnosis Result: " << endl;
    cout << result << endl;
    return 0;
}