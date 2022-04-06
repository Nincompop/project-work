//Inputting header files
#include <iostream>

#include <fstream>
/*f stream contains ifstream and ofstream. In simple words,
ifstream opens the file for reading and ofstream opens the file for writing */

#include <sys/stat.h>


#include <ctime>
//ctime contains the function ctime that helps to convert data and time to user readable format.

using namespace std;

//Start of the code
int main () {
     string option;
     
     //Creating a menu for user to choose from
	 menu:
	 cout << endl;
     cout << "MINI FILE SYSTEM" << endl;
     cout << "_______________________" << endl;
     cout << "[1] SAVE content in a file." << endl;
     cout << "[2] VIEW content of a file." << endl;
     cout << "[3] OBTAIN size of the file." << endl;
     cout << "[4] Get CREATION & MODIFICATION date" << endl;
     cout << "[5] CLEAR contents of the file. " << endl;
     cout << "[6] DELETE the file." << endl;
     cout << "[7] EXIT" << endl;
     cout << "_______________________" << endl;
     cout << "\n          Enter Your Choice:	";
     
     cin>>option;
     if (option == "1") {
       string textToSave;
       cout << "ENTER THE STRING YOU WANT TO SAVE HERE:";
       
       
       /* We declare a dummy getline here because we need to remove the extra
       newline from the buffer. This extra newline will consume the next getline. So,
       we create a dummy getline which will get consumed */
       string Dummy;
	   getline(cin,Dummy);
	   
	   
       getline(cin,textToSave);
       
       /* We use ofstream object to open a file for writing. File is the name
       of our object here. We will put textToSave in File. If File.txt does not exist
	   ofstream will also create a new file */
       ofstream File ("file.txt");

       File << textToSave;
       
       
       cout << "" << endl<< endl<< endl<< endl<< endl<< endl;
       system("pause");
       ifstream F1 ("file.txt");
       ofstream F2 ("file_copy.txt");
	   string ch;
	   if(F1 && F2){
		  while(getline(F1,ch)){
			  F2<<ch<<"\n";
		  }
	  }
	   
		goto menu;
     }
     
     
     else if(option == "2") { 
          cout << "The text stored in the file is:" << endl;
          
          /*rdbuf redirects the stream in file.txt to the standard output cout, 
		  and user can see contents of the file. */

        cout <<(ifstream ("file.txt")).rdbuf();
        
		cout<<"\n\n";
    	system("pause");
 		goto menu;}


      else if (option == "3") {
           ifstream File("file.txt");
           
           /*We use 2 functions here. seekg() is used to move the get pointer to a desired location 
		   with respect to a reference point. tellg() is used to know where the get pointer is in a file.
		   
		   Firstly, we will use seekg to move pointer to the last charachter and then we will use
		   tellg to tell the position of pointer. Since 1 charachter=1 byte, it will tell the
		   size of the file in bytes.*/
		   
   			File.seekg(0, ios::end);
   			int file_size = File.tellg();
   			
   			
   			cout<<"Size of the file is"<<" "<< file_size<<" "<<"bytes";
   		cout << "\n\n\n";
  		system("pause");
		goto menu;}


      else if (option == "4") {
      	
      	
   		struct stat file;
   		stat("file.txt", &file);
   		cout << "Created: " << ctime(&file.st_ctime); //Ctime stands for created time
   		cout << "Modified: " <<ctime(&file.st_mtime); //Mtime stands for modified time
		   
   		
   		
   		system("pause");
		goto menu;
		}

     else if (option == "5") { 
     
     //Truncate command in ios namespace is used to clear file's data.
		ofstream ("file.txt", ios::trunc);
		
        cout << "Contents of the file are cleared \n\n" ;
 		system("pause");
		goto menu;
		}
		
     else if (option == "6") {
     	
     	//remove function is used to delete a file.
    	remove("file.txt");
    	
    	
    	cout << "\n\n\n\n";
 		cout << "File Deleted" << endl;
 		system("pause");
		goto menu;
		}
		
		
     else if (option == "7") {
 		return 0;
		 }
		 
     else{
			cout<<"\t\t\tPlease input a valid number.\n";
			system("pause");
			goto menu;
			}
			
	 return 0;
	 }