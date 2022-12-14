#include <iostream>
#include <iomanip>
using namespace std;

class Student{
	private:
		string student_ID, student_name;
		int quiz_marks[4], assignment_marks[2], mid_term_marks, final_term_marks;
		float total_marks;
	public:
		
		
		Student(){
			student_ID = "none";
			student_name = "none";
			for(int i=0; i<4; i++){
				quiz_marks[i] = 0;
			}
			for(int j=0; j<2; j++){
				assignment_marks[2] = 0;
			}
			mid_term_marks = 0;
			final_term_marks = 0;
			total_marks = 0;
		}
		
		Student(string id, string name, int quiz[4], int assign[2], int mids, int finals){
			student_ID = id;
			student_name = name;
			for(int i=0; i<4; i++){
				quiz_marks[i] = quiz[i];
			}
			for(int j=0; j<2; j++){
				assignment_marks[2] = assign[2];
			}
			mid_term_marks = mids;
			final_term_marks = finals;
		}
		
		void enterData(){
			int mid_flag = 1, final_flag = 1;
			
			cout<<"Enter Student ID: ";
			cin>>student_ID;
			cout<<"Enter Student Name: ";
			cin>>student_name;
			for(int i=0; i<4; i++){
				cout<<"Enter marks for Quiz #"<<i+1<<" <out of 10>: ";
				cin>>quiz_marks[i];
				if(quiz_marks[i]>=0 && quiz_marks[i]<=10){
					continue;
				}
				else{
					cout<<"Invalid Marks, Marks should be between 0-10."<<endl;
					i--;
				}
			}
			for(int j=0; j<2; j++){
				cout<<"Enter marks for Assignment #"<<j+1<<"<out of 20>: ";
				cin>>assignment_marks[j];
				if(assignment_marks[j]>=0 && assignment_marks[j]<=20){
					continue;
				}
				else{
					cout<<"Invalid Marks, Marks should be between 0-20."<<endl;
					j--;
				}
			}
			while(mid_flag == 1){
				cout<<"Enter Marks for Mid Terms <out of 40>: ";
				cin>>mid_term_marks;
				if(mid_term_marks>=0 && mid_term_marks<=40){
					mid_flag = 0;
				}
				else{
					cout<<"Invalid Marks, Marks should be between 0-40."<<endl;
					mid_flag = 1;
				}
			}
			while(final_flag == 1){
				cout<<"Enter Marks for Final Terms <out of 60>: ";
				cin>>final_term_marks;
				if(final_term_marks>=0 && final_term_marks<=60){
					final_flag = 0;
				}
				else{
					cout<<"Invalid Marks, Marks should be between 0-60."<<endl;
					final_flag = 1;
				}
			}
		}

		void calculateResult(){
			int obt_quiz=0, obt_assignment=0;
			
			for(int k=0; k<4; k++){
				obt_quiz += quiz_marks[k];
			}
			
			for(int l=0; l<2; l++){
				obt_assignment += assignment_marks[l];
			}
			
			
			total_marks = ((obt_quiz/40.0)*10) + ((obt_assignment/40.0)*20) + ((mid_term_marks/40.0) * 30) + ((final_term_marks/60.0) * 40);
			
		}
		
		void displayData(){
			
			cout.setf(ios::left, ios::adjustfield);
			cout<<setw(15)<<student_ID<<setw(15)<<student_name<<setw(15)<<mid_term_marks<<setw(15)<<final_term_marks<<setw(15)<<total_marks<<endl;
		}
};

int main(){
	Student* S[3];
	
	int quiz[4]= {1, 2, 1, 3};
	int assignment[2] = {5, 7};
	
	S[0] = new Student("BC000000000", "Name", quiz, assignment, 25, 45);
	S[1] = new Student;
	S[2] = new Student;
	
	S[0]->calculateResult();
	
	S[1]->enterData();
	S[1]->calculateResult();
	
	S[2] = S[1];
	
	cout.setf(ios::left, ios::adjustfield);
	cout<<setw(15)<<"StudentID"<<setw(15)<<"StudentName"<<setw(15)<<"MidTermMarks"<<setw(15)<<"FinalTermMarks"<<setw(15)<<"TotalMarks"<<endl;
	cout<<setw(15)<<"---------------"<<setw(15)<<"---------------"<<setw(15)<<"---------------"<<setw(15)<<"---------------"<<setw(15)<<"---------------"<<endl;
	S[0]->displayData();
	S[1]->displayData();
	S[2]->displayData();
}
