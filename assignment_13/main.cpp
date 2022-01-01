//
//  Created by Sardorbek Madaminov on 2021/12/09.

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <map>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::ifstream;
using std::map;
using std::string;

int main()
{
    ifstream fin;
    map<string, int> mapNumReviewers;
    map<string, int> mapSumReviews;

    fin.open("ratings.txt");
    if (fin.fail())
    {
        cout << "Input file failed opening. \n";
        exit(1);
    }

    int numRatings;
    fin >> numRatings;
    fin.ignore(2, '\n');

    for (int i = 0; i < numRatings; i++)
    {
        string title;
        getline(fin, title);

        title = title.substr(0, title.length());

        int rating;
        fin >> rating;
        fin.ignore(2, '\n');

        if (mapNumReviewers.find(title) == mapNumReviewers.end())
        {
            mapNumReviewers[title] = 1;
        }
        else
        {
            mapNumReviewers[title]++;
        }

        if (mapSumReviews.find(title) == mapSumReviews.end())
        {
            mapSumReviews[title] = rating;
        }
        else
        {
            mapSumReviews[title] += rating;
        }
    }
    fin.close();

    map<string, int>::const_iterator iter;
    for (iter = mapNumReviewers.begin();
         iter != mapNumReviewers.end(); iter++)
    {
        string title = iter->first;
        int numReviewers = iter->second;
        int sumRatings = mapSumReviews[iter->first];

        cout << title << " : " << numReviewers << " reveiwers. "
             << "Average of  " << static_cast<double>(sumRatings) / numReviewers << "/5" << endl;
    }

    cout << endl;
    return 0;
}
