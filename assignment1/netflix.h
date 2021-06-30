/***************************************************************************
 * * Program: netflix.h
 * * Author: XiYuan Huang
 * * Date: 10/7/2018
 * * Description: The program includes all the function prototypes. 
 * * Input: N/A
 * * Output: N/A
 * *************************************************************************/

#ifndef NETFLIX_H
#define NETFLIX_H
#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>


using namespace std;

struct movie {
	string title; //movie title
	int num_actors; //number of actors in the film
	string * actors; //array of actors
	float rating;
	bool suggested; //true/false of whether this movie was suggested for you
};
struct genre {
	string genre_name; //name of genre
	movie *m; // array of movie structs	
	int num_movies; //number of movies in this category
}; 


genre* create_genres(int);
void get_genre_data(genre *, int, ifstream &);
movie* create_movies(int);
void get_movie_data(movie *, int, ifstream &); 
void delete_info(genre **, int);
void most_movie_genre(genre* array, int genreNum);
void highest_rating_movie(genre* array, int genreNum);
void most_actors_movie(genre* array, int genreNum);	
void suggested_movies(genre* array, int genreNum);
void average_genre(genre* array, int genreNum);
void genre_above_average(genre* array, int genreNum, float user_input);
void movie_sorting(genre* array, int genreNum);

//void valid_input(string input);

#endif
