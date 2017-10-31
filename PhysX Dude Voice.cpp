# include<iostream.h>
# include<conio.h>
# include<string.h>
# include<time.h>
# include<math.h>
# include<stdlib.h>
# include<dos.h>
# include<stdio.h>
# include<fstream.h>
#include<windows.h>
# define RESPONSE_LENGTH 650
# define NO_OF_RESPONSE 20
# define MAX_KEYWORDS 2000
# define TRANSPOSE 12
# define MAX_USER_INPUT 100
# define MAX_KWD_LEN 2000


// for getting the user name
char user[30];
int i;
// for word transpositions
char wordin[TRANSPOSE][RESPONSE_LENGTH];
char wordout[TRANSPOSE][RESPONSE_LENGTH];
int RanNum(int max);
void global_initialization();
class initprog
{
public:
char user_input[MAX_USER_INPUT];
char keyword[300];
int keyword_found;
int no_of_keywords;
int no_input;
	// constructor
	initprog()
	{
	no_of_keywords=-1;
	no_input=0;
	}
}ip;

class resp
{
int total_response;
int lastl_response;
char total_responses[NO_OF_RESPONSE][RESPONSE_LENGTH];
char word[MAX_KWD_LEN];

public:
    resp speak(string apple);
	// constructor
	resp()
	{
	total_response=0;
	lastl_response=-1;
	}
	int getcount()
	{
	return lastl_response;
	}
	void addword(char str[MAX_KWD_LEN])
	{
	strcpy(word,str);
	}
	char * getword()
	{
	return word;
	}
	void addresp(char  str[RESPONSE_LENGTH])
	{
	strcpy(total_responses[++lastl_response],str);
	}
	void display_resp(int num);
	void quit_display_resp(int num);

};
resp Moses;
resp resp::speak(string apple){
    string command = "tts -v 8 \"" + apple + "\"";    
    const char* charCommand = command.c_str();      
    system(charCommand);   
}
void display_logo()
{
system("color 70");
cout<<"	   PhysXDude    P        P     PhysX       Dude             "<<endl;
 
cout<<"	   P        P    H        H      H          H        "<<endl;
 
cout<<"	   H      H      Y        Y        Y      Y         "<<endl;
  
cout<<"	   Y    Y        SSSSSSSSSS          S  S                    "<<endl;
 
cout<<"	   S             X         X           X                  "<<endl;
 
cout<<"	   X             X         X           X               "<<endl;
 cout<<"\n\n\t\tTHIS IS UNDER THE COPY RIGHT OF MOSES PAUL.R(C)"; 
}
void display_line()
{
int width=800;
int i=0;
int x=wherex();
int y=wherey()+1;
x=40;
for(int k=0;k<40;k++)
{
 
gotoxy(x+k,y);
cout<<(char)2400;
gotoxy(x-k,y);
 
cout<<(char)2400;
}
cout<<"\n";
}

void resp :: display_resp(int num)
	{
	cout<<"PhysX Dude >> ";
	for(int i=0;i<strlen(total_responses[num]);i++)
	{
		// for deliberate typing errors
		if(RanNum(6)==0)
		{       char c=RanNum(100);
			if(c=='\n' || c=='\b' || c==13)
				cout<<"w";
			else
				cout<<c;
			 ;
			cout<<"\b";
		}

		if(total_responses[num][i]=='*')
		{
		char * s1=ip.user_input+strlen(ip.keyword);
		short int flag=0;
		for(int m=0;m<TRANSPOSE;m++)
			{
			char * s2=wordin[m];
			char *ptr=NULL;
			ptr=strstr(s1,s2);

			if(ptr!=NULL)
				{
				// transposition word found in the
				// user input
				flag=1;

				// printing text before wordin[m]
				int times=ptr-s1;
				for(int i=0;i<times;i++)
					{
					cout<<ip.user_input[strlen(ip.keyword)+i];
					}
				// printing the wordout
				cout<<wordout[m];
				Moses.speak(wordout[m]);
				// printing the left overs
				char c;
				c=*(ptr+strlen(wordin[m]));
				int t=0;
				while(c!='\0')
					{
					cout<<*(ptr+strlen(wordin[m])+t);
					t++;
					c=*(ptr+strlen(wordin[m])+t);
					}
				}
			} // end of for
			// if flag is still zero , this means no transpose.
			if(0==flag)
			{
			char c;
			c=*(s1+strlen(ip.keyword));
			int t=0;
			while(c!='\0')
				{
				cout<<*(s1+t);
				t++;
				c=*(s1+t);
				}
			} // end of if
			break;
		}
	else
			{
				cout<<total_responses[num][i];
				 Moses.speak(total_responses[i]);
			}
	} // end of for
	cout<<"\n"<<user<<" >> ";
	}
void resp :: quit_display_resp(int num)
{
	cout<<"PhysX Dude > ";
	for(int i=0;i<strlen(total_responses[num]);i++)
	{
		// for deliberate typing errors
		if(RanNum(6)==0)
		{       char c=RanNum(100);
			if(c=='\n' || c=='\b' || c==13)
				cout<<"w";
			else
				cout<<c;
			 ;
			cout<<"\b";
		}
		cout<<total_responses[num][i];
	
	} // end of for
}
resp keys[MAX_KEYWORDS];
int RanNum(int max)
{
randomize();
return rand() % max;
}
void find_keyword()
{
int len=0;
int lenkey=0;
int key_no=0;
char teststr[50];
while((ip.keyword_found==0) &&(key_no!=MAX_KEYWORDS))
{
// getting the length of the keyword
lenkey=strlen(keys[key_no].getword());

char *ptr=NULL;
ptr=strstr(ip.user_input,keys[key_no].getword());
if (ptr!=NULL)
	{
	// keyword found !
	ip.keyword_found=1;
	ip.no_of_keywords=key_no;
	strcpy(ip.keyword,keys[key_no].getword());
	break;
	}
//////////////////////////////////////////
for( i=0;i<lenkey;i++)
	{
	teststr[i]=ip.user_input[i];
	}
teststr[i]='\0'; 
if (strcmp(teststr,keys[key_no].getword())==0)
	{
	     ip.keyword_found=1;
	     ip.no_of_keywords=key_no;
	     strcpy(ip.keyword,keys[key_no].getword());
	}
//////////////////////////////////////////
key_no++;
}
}

void read_from_file()
{
ifstream fin;
int index=-1;
fin.open("Data.dat");
char line[RESPONSE_LENGTH];
while(fin)
{
	fin.getline(line,RESPONSE_LENGTH);
	char *ptr=NULL;
	ptr=strstr("@NULL@",line);
	if(strlen(line)<1)
	{
		break;
	}
	else if(ptr!=NULL)
	{
		// the next line is a keyword
		fin.getline(line,RESPONSE_LENGTH);
		keys[++index].addword(line);
	}
	else
	{
		// it is a response
		keys[index].addresp(line);
	}

} // end of while
} // end of function


void main()
{
clrscr();
resp Moses;
display_line();
display_logo();
display_line();
// for initializing the global variables
global_initialization();
// upon  logging in
resp signon;
signon.addresp("HI, I'M Physics Dude. What's Up ?");
signon.addresp("HOW IS THE ROTATION OF YOUR EARTH GOING TODAY ?");

// when no key found
resp no_val;
no_val.addresp("WHICH PART OF MY PLANET ARE YOU FROM");
no_val.addresp("WHAT DOES THAT SUPPOSED TO MEAN ?");
no_val.addresp("OH I SEE");
no_val.addresp("I'M NOT SURE  WHAT YOU ARE TALKING ABOUT ");
no_val.addresp("WHAT'S THAT SUPPOSED TO MEAN ?");
no_val.addresp("CAN YOU CLARIFY  ?");
no_val.addresp("THAT'S INTERESTING...");
no_val.addresp("AND ????");

resp bye;
bye.addresp("GOOD BYE, HAVE A NERDY DAY DAY...");
bye.addresp("BYE, HOPE TO SEE YOU SOON...");

resp null_resp;
resp speaking = null_resp;
null_resp.addresp("WHAT ?");
null_resp.addresp("HOW AM I SUPPOSED TO TALK TO YOU ,IF YOU DON'T SAY ANYTHING ?");
// reading data from dictionary
read_from_file();

// STARTING CONVERSATION WITH THE USER
// welcoming the user
Moses.speak("Welcome ,to ,Physics ,Dude ,A ,Chat ,Bot ,Programmed, By ,Moses ,Paul");
cout<<"PhysX Dude > WHAT'S YOUR NAME NERD ?(PLS TYPE IN CAPS)\n";
cin>>user;
display_line();
display_line();
signon.display_resp(RanNum(signon.getcount()));
fflush(stdin);
gets(ip.user_input);
strcpy(ip.user_input,strupr(ip.user_input));
while(strcmp(ip.user_input,"SEEYA")!=0)
{
	find_keyword();
if(strlen(ip.user_input)<1)
{
	null_resp.display_resp(RanNum(null_resp.getcount()));
	
}
else if(ip.keyword_found==1)
	{
	keys[ip.no_of_keywords].display_resp(RanNum(keys[ip.no_of_keywords].getcount()));
	}
else if(strlen(ip.user_input)>1)
	{
	no_val.display_resp(RanNum(no_val.getcount()));
	}
else 
   {
   	no_val.display_resp(RanNum(no_val.getcount()));
   }
// again returning to normal values of the data items
strcpy(ip.user_input," ");
ip.no_of_keywords=-1;
ip.keyword_found=0;
fflush(stdin);
gets(ip.user_input);
strcpy(ip.user_input,strupr(ip.user_input));
} // end of while
	bye.quit_display_resp(RanNum(null_resp.getcount()));
	cout<<endl;
	display_line();
	display_line();
cout<<"Hope you Enjoyed This Program PhysX Dude a.k.a Moses Programmed In Cpp\n";
Moses.speak("Hope you Enjoyed This Program Physics Dude a.k.a Moses Programmed In Cpp");
	display_line();
	display_line();
getch();
}


void global_initialization()
{
strcpy(wordin[0],"ARE");
strcpy(wordout[0],"AM");

strcpy(wordin[1],"AM");
strcpy(wordout[1],"ARE");

strcpy(wordin[2],"WERE");
strcpy(wordout[2],"WAS");

strcpy(wordin[3],"WAS");
strcpy(wordout[3],"WERE");

strcpy(wordin[4],"YOU");
strcpy(wordout[4],"ME");

strcpy(wordin[5]," I ");
strcpy(wordout[5],"YOU");

strcpy(wordin[6],"YOUR");
strcpy(wordout[6],"MY");

strcpy(wordin[7],"MY");
strcpy(wordout[7],"YOUR");

strcpy(wordin[8],"I'VE");
strcpy(wordout[8],"YOU'VE");

strcpy(wordin[9],"YOU'VE");
strcpy(wordout[9],"I'VE");

strcpy(wordin[10],"I'M");
strcpy(wordout[10],"YOU'RE");

strcpy(wordin[11],"YOU'RE");
strcpy(wordout[11],"I'M");

strcpy(wordin[12],"ME");
strcpy(wordout[12],"YOU");

strcpy(wordin[13],"YOU");
strcpy(wordout[13],"ME");

}
