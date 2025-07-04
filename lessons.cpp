#include <iostream>
#include <clocale>
#include <string>
#include <vector>
#include <time.h>
#include <cstdlib>

using namespace std;

class student{
	public:
	string studentName;
	string studentSurname;
	int studentCounter;
	void studentRegistration();
	vector<string> addLesson;

};

class teacher:public student{
	public:
	string teacherName;
	string teacherSurname;
	void teacherRegistration();
	int teacherCounter;
	int teacherPassword;
};

class lesson:public teacher{
	public:
	void lessonsCreate();
	string lessonsName;
	void lessonsList();
	void lessonRegistration();
	void show_student_lessons();
	void students_taking_lesson();
	void all_students_lessons();
};
vector<student> students;
vector<teacher> teachers;
vector<lesson> lessons;


void student::studentRegistration(){
	
    student registration;
	
	cout << "Ka� ��renci kay�t edilecek: ";
	cin >> studentCounter;
	
	cout << endl;
	
	for(int i = 1; i<studentCounter+1;i++){
	
	cout << i << ". ��rencinin ismi: ";
	cin >> registration.studentName;
	
	cout << i << ". ��rencinin soyismi: ";
	cin >> registration.studentSurname;
	
	cout << endl;
	
	students.push_back(registration);
	
}
	
} 

void teacher::teacherRegistration(){
	
	teacher registration;
	
	cout << "Ka� ��retmen kay�t edilecek: ";
	cin >> teacherCounter;
	
	srand(time(0));
	
	for(int j = 1; j<teacherCounter+1;j++){
	
	cout << j << ". ��retmenin ismi: ";
	cin >> registration.teacherName;
	
	cout << j << ". ��retmenin soyismi: ";
	cin >> registration.teacherSurname;
	
    registration.teacherPassword = rand()%9000+1000;
    
    cout << "�ifre: " << registration.teacherPassword << endl;
    cout << endl;
	
	teachers.push_back(registration);
	
}
	
} 



void lesson::lessonsCreate(){
	
	cout << "----- ��retmen Giri�i -----"<<endl;
	cout << "�sminizi giriniz: ";
	cin >> teacherName;
	
	cout << "�ifre: ";
	cin >> teacherPassword;
	
	
	bool isFind = false;
	lesson enter;
	
	for(int k =0;k<teachers.size();k++){
	if(teachers[k].teacherName==teacherName && teachers[k].teacherPassword==teacherPassword){
	
	isFind = true;
	
	cout << "Olu�turmak istedi�iniz dersin ismi: ";
	cin >> enter.lessonsName;
	
	lessons.push_back(enter);
}
}

if(isFind==false){
	cout << "Girilen bilgiler yanl��!!" << endl;
	cout << endl;
}

}

void lesson::lessonsList(){
	
	cout << "----- DERSLER -----" << endl;
	
	for(int x = 0;x<lessons.size();x++){
		
		cout << "- " << lessons[x].lessonsName << endl;
			
	}
	
	cout << endl;
}

void lesson::lessonRegistration(){
	
	
	cout << "----- ��renci Giri�i -----" << endl;
	cout << endl;
	cout << "�sminizi giriniz: ";
	cin >> studentName;
	
	cout << "Soyisminizi giriniz: ";
	cin >> studentSurname;
	cout << endl;
	

	bool found = false;
	int number;
	
	for(int y =0;y<students.size();y++){
	if(students[y].studentName==studentName && students[y].studentSurname==studentSurname){
	
	found=true;
	
	cout << "Ka� ders se�mek istersiniz: ";
	cin >> number;
	cout << endl;
	
	for(int z =0;z<number;z++){
	
	cout << "Se�mek istedi�iniz dersin ismi: ";
	cin >> lessonsName;
	cout << endl;
	
	students[y].addLesson.push_back(lessonsName);
}

}
}
	
	
}

void lesson::show_student_lessons(){
	
	cout << "�sminizi giriniz: ";
	cin >> studentName;
	
	cout << "Soyisminizi giriniz: ";
	cin >> studentSurname;
	
	for(int a =0;a<students.size();a++){
	if(students[a].studentName==studentName && students[a].studentSurname==studentSurname){
	
	cout << "----- Se�ilen Dersler -----" << endl;
	
    for(int b = 0;b<students[a].addLesson.size();b++){
	
	cout <<  "- " << students[a].addLesson[b]<< endl;

	
}
}
}
	cout << endl;
}

void lesson::students_taking_lesson(){
	
	cout << "Hangi dersi sorgulamak istersiniz: ";
	cin >> lessonsName;
	
	cout << endl;
	cout << lessonsName << " dersini alan ��renciler: "<< endl;
	cout << endl;
	
	for(int c = 0;c<students.size();c++){
		for(int t = 0;t<students[c].addLesson.size();t++){
			if(students[c].addLesson[t]==lessonsName){
				
				cout << "- " << students[c].studentName << endl;
				
			}
			
		}
		
	}
	
	cout << endl;
}

void lesson::all_students_lessons(){
	
	cout << endl;
	
		for(int c = 0;c<students.size();c++){	
			cout << "- �sim: " << students[c].studentName << endl;
			cout << "Se�ilen dersler: " << endl;
		for(int t = 0;t<students[c].addLesson.size();t++){
			
				cout << "- " << students[c].addLesson[t] << endl;
					
		}
		
	}
	cout << endl;
	
	
	
	
	
}






void console(){
	cout << endl;
	cout << "----- DERS KAYIT -----" << endl;
	cout << endl;
	cout << "1- ��renci ekle" << endl;
	cout << "2- ��retmen ekle" << endl;
	cout << "3- Yeni ders olu�tur" << endl;
	cout << "4- ��renciye ders ata" << endl;
	cout << "5- ��rencinin ald��� dersler" << endl;
	cout << "6- Dersi alan ��renciler" << endl;
	cout << "7- T�m ��renci ve dersleri listele	" << endl;
	cout << "8- ��k��" << endl;
	cout << endl;
	cout << "----- DERS KAYIT -----" << endl;
	cout << endl;
}

int main() {
	
	setlocale(LC_ALL,"Turkish");
	
	int selection = 0;
	
	lesson select;
	
	do{
		
		console();
		
		cout << "Yapmak istedi�iniz i�lemi se�iniz: ";
		cin >> selection;
		
		cout << endl;
	
	switch(selection){
		
		case 1:
			select.studentRegistration();
		break;
		
		case 2:
			select.teacherRegistration();
		break;
		
		case 3:
			select.lessonsCreate();
		break;	
		
		case 4:
			select.lessonsList();
			select.lessonRegistration();
		break;
		
        case 5:
	        select.show_student_lessons();
        break;
        
        case 6:
        	select.students_taking_lesson();
        break;
        
        case 7:
        	select.all_students_lessons();
        break;
        
        case 8:
        	break;	
			
			
	}}while(selection != 8);

	return 0;
}
