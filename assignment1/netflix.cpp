/***************************************************************************
 * * Program: netflix.cpp
 * * Author: XiYuan Huang
 * * Date: 10/7/2018
 * * Description: This program has the sorting and searching functions which 
 * 		  output the detail of the movies.
 * * Input: The parameters of each function
 * * Output: The detail of the movies which depends on the user's option.
 * *************************************************************************/

#include <iostream>
#include <fstream>
#include <cstring>
#include "netflix.h"
#include <cstdlib>


using namespace std;


//This function creates the array for genres
genre* create_genres(int genreNum)
{
	genre* array = new genre[genreNum];
	return array;

}

//This function takes the date from the file and 
//put it into genre array
void get_genre_data(genre * array, int genreNum, ifstream& infile)
{
	for(int i = 0; i < genreNum; i++){
		infile >> array[i].genre_name;
		infile >> array[i].num_movies;
		array[i].m = create_movies(array[i].num_movies);
		int numMovie = array[i].num_movies;
		get_movie_data(array[i].m, numMovie, infile); 		
	}
}

//This function creates the array for movies
movie* create_movies(int movieNum)
{
	movie* array = new movie[movieNum];
	return array;

}

//This function takes the date from the file and
//put it into movie array
void get_movie_data(movie* array , int movieNum , ifstream& input)
{
	string tempSuggested;
	for(int i = 0; i < movieNum; i++){
		input >> array[i].title;
		input >> array[i].rating;
		input >> array[i].num_actors;
		array[i].actors = new string[array[i].num_actors];
		for(int j = 0; j < array[i].num_actors; j++){
			input >> array[i].actors[j];		
		}
		input >> tempSuggested;
		if(tempSuggested == "true"){
			array[i].suggested = 1;
		}else{
			array[i].suggested = 0;
		}	
	}

}

//The funciton outputs the genre with most movies
void most_movie_genre(genre* array, int genreNum)
{
	int mostMovie = 0;
	for(int i = 0; i < (genreNum -1); i++){
		mostMovie = array[i].num_movies;
		for(int j = i + 1; j < genreNum; j++){
			if(array[j].num_movies > mostMovie){
				mostMovie = array[j].num_movies;
			}	
		}

	}

	cout << "the genre with the most movies" << endl;
	cout << "the number of movies is: " << mostMovie << endl;

	for(int i = 0; i < genreNum; i++){
		if(array[i].num_movies == mostMovie){
			cout << array[i].genre_name << " ";
			cout << array[i].num_movies << endl;		
			for(int j = 0; j < array[i].num_movies; j++){
				cout << array[i].m[j].title << " ";
				cout << array[i].m[j].rating << " ";
				cout << array[i].m[j].num_actors << " ";
				for(int z = 0; z < array[i].m[j].num_actors; z++){
					cout << array[i].m[j].actors[z] << " ";
				}
				if(array[i].m[j].suggested == 1){
					cout << "true" << endl;
				}else{
					cout << "false" << endl;
				}
			} 
		}
	}

}		

//This function outputs the movies with the highest rating
void highest_rating_movie(genre* array, int genreNum)
{
	float highestRating, minRating, temp;
	for(int i = 0; i < genreNum; i++){
		for(int j = 0; j < array[i].num_movies; j++){	
			minRating = array[i].m[j].rating;	
			if(highestRating < minRating){
				highestRating = minRating;	
			}	
		}
	}
	cout << "the movie with the highest rating " << endl;
	cout << "the highest rating is: " << highestRating << endl;

	for(int i = 0; i < genreNum; i++){
		for(int j = 0; j < array[i].num_movies; j++){
			if(array[i].m[j].rating == highestRating){
				cout << array[i].m[j].title << " ";
				cout << array[i].m[j].rating << " ";
				cout << array[i].m[j].num_actors << " ";

				for(int z = 0; z < array[i].m[j].num_actors; z++){
					cout << array[i].m[j].actors[z] << " ";
				}
				if(array[i].m[j].suggested == 1){
					cout << "true" << endl;
				}else{
					cout << "false" << endl;
				}
			} 
		}

	}
}

//This funciton output the movies with the most actors
void most_actors_movie(genre* array, int genreNum)
{
	int mostActors = 0, minActors = 0;
	for(int i = 0; i < genreNum; i++){
		for(int j = 0; j < array[i].num_movies; j++){
			minActors = array[i].m[j].num_actors;
			if(mostActors < minActors){
				mostActors = minActors;
			}
		}
	}

	cout << "the movie with the most actors and who those actors are" << endl; 	
	cout << "the number of actors is: " << mostActors << endl;

	for(int i = 0; i < genreNum; i++){
		for(int j = 0; j < array[i].num_movies; j++){
			if(array[i].m[j].num_actors == mostActors){
				cout << array[i].m[j].title << " ";
				cout << array[i].m[j].rating << " ";
				cout << array[i].m[j].num_actors << " ";

				for(int z = 0; z < array[i].m[j].num_actors; z++){
					cout << array[i].m[j].actors[z] << " ";
				}
				if(array[i].m[j].suggested == 1){
					cout << "true" << endl;
				}else{
					cout << "false" << endl;
				}
			} 
		}

	}
}

//This function outputs the suggested movies
void suggested_movies(genre* array, int genreNum)
{
	cout << "all movies that are suggested for you" << endl;
	for(int i = 0; i < genreNum; i++){
		for(int j = 0; j < array[i].num_movies; j++){
			if(array[i].m[j].suggested == 1){
				cout << array[i].m[j].title << " ";
				cout << array[i].m[j].rating << " ";
				cout << array[i].m[j].num_actors << " ";

				for(int z = 0; z < array[i].m[j].num_actors; z++){
					cout << array[i].m[j].actors[z] << " ";
				}
				if(array[i].m[j].suggested == 1){
					cout << "true" << endl;
				}else{
					cout << "false" << endl;
				}
			} 
		}

	}
}

//The funciton output the genre with an average movie rating
//above a certain amount
void genre_above_average(genre* array, int genreNum, float user_input)
{
	int count = 0;
	float averageRating, average;
	float ratingArray[genreNum];
	for(int i = 0; i < genreNum; i++){
		for(int j = 0; j < array[i].num_movies; j++){	
			average += array[i].m[j].rating;
			count++;
		}
		averageRating = average / count;
		average = 0;
		count = 0;
		ratingArray[i] = averageRating;
	}
	cout << "the genre with an average movie rating"; 
	cout << " above that number is: " << endl;

	for(int i = 0; i < genreNum; i++){
		if(user_input < ratingArray[i]){
			cout << array[i].genre_name <<" ";
			cout << array[i].num_movies << endl;	
			for(int j = 0; j < array[i].num_movies; j++){
				cout << array[i].m[j].title << " ";
				cout << array[i].m[j].rating << " ";
				cout << array[i].m[j].num_actors << " ";
				for(int z = 0; z < array[i].m[j].num_actors; z++){
					cout << array[i].m[j].actors[z] << " ";
				}
				if(array[i].m[j].suggested == 1){
					cout << "true" << endl;
				}else{
					cout << "false" << endl;
				}
			}		 
		}

	}

}

//This funciton outputs the average movie rating in each genre
void average_genre(genre* array, int genreNum)
{
	int count = 0;
	float averageRating = 0, average = 0;
	float* ratingArray =new float[genreNum];
	for(int i = 0; i < genreNum; i++){
		for(int j = 0; j < array[i].num_movies; j++){	
			average += array[i].m[j].rating;
			count++;
		}
		averageRating = average / count;
		average = 0;
		count = 0;
		ratingArray[i] = averageRating;
	}

	for(int i = 0; i < genreNum; i++){
		cout << "the average rating for all movies in the genre of " << array[i].genre_name << " ";
		cout << "is " << ratingArray[i] << endl;
	}
	delete [] ratingArray;
}	

void movie_sorting(genre* array, int genreNum)
{
	int count = 0;
	for(int i = 0; i < genreNum; i++){
		count += array[i].num_movies;
	}
	movie* newArray = create_movies(count);

	int placeholder = 0;		
	for(int i = 0; i < genreNum; i++){
		for(int j = 0 ; j < array[i].num_movies; j++){
			newArray[placeholder] = array[i].m[j];
			placeholder++;
		}	
	}

	int startScan, minIndex, Index;
	float minValue;


	for(int startScan = 0; startScan < (count-1); startScan++){
	  minIndex = startScan;
	  minValue = newArray[startScan].rating;
	  for(int Index = startScan + 1; Index < count; Index++){
	  if(newArray[Index].rating < minValue){
	  minValue = newArray[Index].rating;
	  minIndex = Index;
	  }
	  }
	  newArray[minIndex].rating = newArray[startScan].rating;
	  newArray[startScan].rating = minValue;
	  }



	  for(int j = 0; j < count; j++){
	  cout << newArray[j].title << " ";
	  cout << newArray[j].rating << " ";
	  cout << newArray[j].num_actors << " ";

	  for(int z = 0; z < newArray[j].num_actors; z++){
	  cout << newArray[j].actors[z] << " ";
	  }
	  if(newArray[j].suggested == 1){
	  cout << "true" << endl;
	  }else{
	  cout << "false" << endl;
	  }

	  }


}

//This funciton deletes the array
void delete_info(genre ** array, int genreNum)
{
	for(int i = 0; i < genreNum; i++){
		for(int j = 0; j < (*array)[i].num_movies; j++){
			delete [] (*array)[i].m[j].actors;
		}
		delete [] (*array)[i].m;
	}
	delete [] *array;
}



