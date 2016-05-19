#include <iomanip>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class MediaItem {
	public:
		//The following are setters and getters for the MediaItem class
		void setID(string mID);
		void setTitle(string mtitle);
		void setGenre(string mgenre);
		void setStatus(string mstatus);
		void setType(string mType);
		//Virtual function PrintData. Call the getters for the respective functions
		virtual void PrintData() {
			cout << "Media ID: " << getID() << endl;
			cout << "Media Type: " << getType() << endl;
			cout << "Media Title: " << getTitle() << endl;
			cout << "Genre: " << getGenre() << endl;
			cout << "Current Status: " << getStatus() << endl;
		}
		string getID() const;
		string getType() const;
		string getGenre() const;
		string getTitle() const;
		string getStatus() const;
	private:
		string ID, title, genre, status, tType;
};

class MovieItem:public MediaItem 
{
	public:
		void setActors(string mactors, int mcounter); //Counter variable is used as a place holder
		string getActors();
		int numAct = 0;
		vector<string> actors = vector<string> (20); //Vector to hold the actors' names
		//Inheritance
		void PrintData(){
			cout << "Actors: ";
			for (int x = 0; x < numAct; ++x){
				cout << actors.at(x);
			}
		}
};

class MusicItem:public MediaItem
{
	public:
		void setArtists(string martists, int acounter);
		string getArtists();
		int numArt = 0;
		vector<string> artists = vector<string> (20);
		void PrintData(){
			cout << "Artists: ";
			for (int x = 0; x < numArt; ++x){
				cout << artists.at(x);
				if (x < (numArt-1)){
					cout << ", ";
				}
			}
		}
};
//Function setters
void MediaItem::setID(string mID) {
	ID = mID;
}
void MediaItem::setType(string mType) {
	tType = mType;
}
void MediaItem::setTitle(string mTitle) {
	title = mTitle;
}
void MediaItem::setGenre(string mgenre) {
	genre = mgenre;
}
void MediaItem::setStatus(string mstatus) {
	status = mstatus;
}
//MovieItem specific function
void MovieItem::setActors(string mactors, int counter){
	actors.at(counter) = mactors;
	//Counter is used for, for loop in respective function
	numAct = counter;
}
//MusicItem specific function
void MusicItem::setArtists(string martists, int acounter){
	artists.at(acounter) = martists;
	//Counter is used for for loop above
	numArt = acounter;
}
//Function getters
string MediaItem::getID() const{
	return ID;
}

string MediaItem::getStatus() const{
	return status;
}

string MediaItem::getType() const{
	return tType;
}

string MediaItem::getTitle() const {
	return title;
}
string MediaItem::getGenre() const {
	return genre;
}

/*string MediaItem::getActors(){
	string actorsList = "";
	for (int i = 0; i < numAct; ++i)
	{
		actorsList += actors1V[i]; //Add actor's name in [i] element to actorsList string 
		if (i < (numAct-1))
		{
			actorsList += ", "; //Add a comma after every name save for the last one
		}
	}
	return actorsList; //Returns string
}*/

class List{
	private:
		struct node {
			MediaItem data;
			node* next;
		};
		typedef struct node* nodePtr;
		nodePtr head;
		nodePtr curr;
		nodePtr temp;
	public: //This is where the functions go
		List(); //constructor
		void ListAppend(MediaItem addData);  //adds data(appends)
		void ListRemove(MediaItem delData); //removes data
		void printData();
};

List::List() {  //defining the constructor. For defining the private data.
	head = NULL;
	curr = NULL;
	temp = NULL;
}

void List::ListAppend(MediaItem addData){  //List Append function
	nodePtr n = new node;
	n->next = NULL;
	n->data = addData;
	if(head != NULL){
		curr = head;
		while(curr->next != NULL){
			curr = curr->next;
		}
		curr->next = n;
    }
	else{
		head = n;
    }
}

/*void List::ListRemove(MediaItem delData) { //List remove function
	nodePtr delPtr = NULL;
	temp = head;
	curr = head;
	while (curr != NULL && curr->data != delData) {
		temp = curr;
		curr = curr->next;
	}
	if (curr == NULL) {
		cout << delData << " was not in the list\n";
		delete delPtr;
    }
	else {
		delPtr = curr;
		curr = curr->next;
		temp->next = curr;
		if(delPtr == head) {
			head = head->next;
			temp = NULL;
		}
		delete delPtr;
		cout << "The value " << delData << " was deleted\n";
	}
}*/

void List::printData(){ //print function
	curr = head;
	while(curr != NULL){
		//cout << curr->data << " ";
		curr->data.PrintData();
		curr = curr->next;
		}
}

int main(){
	List onlineMediaItems;
	int artcounter = 0; //Used to keep track of # of artists
	int actcounter = 0; //Used to keep track of # of actors
	MovieItem movie1;
	MusicItem music2; //Movie items
	//Following are string variables
	string input, ID, title, genre, status, name, continueQ = "Y", continueQ2 = "Y", quitQ = "N"; 
	//Prompt user for information and then store it
	cout << "Enter Movie or Music?: ";
	getline(cin, input); cout << endl;
	movie1.setType(input);
	cout << "Enter Media ID: ";
	movie1.setID(input);
	getline(cin, ID); cout << endl;
	cout << "Enter Media Title: ";
	getline(cin, title); cout << endl;
	movie1.setTitle(title);
	cout << "Enter Media Genre: ";
	getline(cin, genre); cout << endl;
	movie1.setGenre(genre);
	cout << "Enter Current Status: ";
	getline(cin, status); cout << endl;
	movie1.setStatus(status);
	cout << "Enter Actor: ";
	getline(cin, name); cout << endl;
	movie1.setActors(name, actcounter);
	actcounter++; //Increase after every actor inputed
	cout << "Continue Y or N: ";
	getline(cin, continueQ);
	cout << endl;
	while (continueQ == "Y"){
		cout << "Enter Actor: ";
		getline(cin, name); cout << endl;
		actcounter++;
		movie1.setActors(name, actcounter);
		cout << "Continue Y or N: "; //Checks if the user wants to add more actors or not
		getline(cin, continueQ);
		cout << endl;
	}
	continueQ = "N";
	onlineMediaItems.ListAppend(movie1); //Store info and add to list
	cout << "Quit Y or N?: ";
	getline(cin, quitQ);
	if (quitQ == "N"){
		continueQ = "Y";
		cout << "Enter Movie or Music?: ";
		getline(cin, input); cout << endl;
		cout << "Enter Media ID: ";
		music2.setID(input);
		getline(cin, ID); cout << endl;
		cout << "Enter Media Title: ";
		getline(cin, title); cout << endl;
		music2.setTitle(title);
		cout << "Enter Media Genre: ";
		getline(cin, genre); cout << endl;
		music2.setGenre(genre);
		cout << "Enter Current Status: ";
		getline(cin, status); cout << endl;
		music2.setStatus(status);
		cout << "Enter Artists: ";
		getline(cin, name); cout << endl;
		music2.setArtists(name, artcounter);
		artcounter++;
		cout << "Continue Y or N: ";
		getline(cin, continueQ);
		cout << endl;
		while (continueQ == "Y"){
			cout << "Enter Artists: ";
			getline(cin, name); cout << endl;
			artcounter++;
			music2.setArtists(name, artcounter);
			cout << "Continue Y or N: ";
			getline(cin, continueQ2);
			cout << endl;
		}
		onlineMediaItems.ListAppend(music2); //Store MediaItem object to list
		cout << endl << "Quit Y or N?: ";
		getline(cin, quitQ);
	}
	cout << endl << "****Print Out********" << endl << endl;
	onlineMediaItems.printData(); //Prints items in linked list
	movie1.PrintData();
	if (quitQ == "N"){
		music2.PrintData();
	}
}