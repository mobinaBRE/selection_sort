#include <iostream>
using namespace std;
class book {
	private:
		int price,ISBN;
		char name[60];
	public:
		book() {}
		void ciin(book s[],int n) {
			for(int i=0; i<n; i++) {
				cout<<"("<<i+1<<") : \n"<<"name : ";
				cin>>s[i].name;
				cout<<"ISBN : ";
				cin>>s[i].ISBN;
				cout<<"price : ";
				cin>>s[i].price;
			}
		}
		void sortprice(book s[],int n) {
			for(int i=0; i<n; i++) {
				int max=0;
				for(int j=0; j<n-i; j++) {
					if(s[max].price<s[j].price)
						max=j;
				}
				book temp;
				temp=s[max];
				s[max]=s[n-i-1];
				s[n-i-1]=temp;
			}
		}
		void sortname(book s[],int n) {
			for(int i=0; i<n; i++) {
				for(int j=i+1; j<n; j++) {
					if(strcmp(s[i].name,s[j].name)>0) {
						book temp=s[i];
						s[i]=s[j];
						s[j]=temp;
					}
				}
			}
		}
		bool deleteISBN(book s[],int n,int isbn) {
			for(int i=0; i<n; i++) {
				if(s[i].ISBN==isbn) {
					for(int j=i; j<n-1; j++) {
						s[j]=s[j+1];
					}
					return true;
				}
			}
			return false;
		}
		void print(book s[],int n) {
			for(int i=0; i<n; i++) {
				cout<<"name :"<<s[i].name<<" ISBN :"<<s[i].ISBN<<" price :"<<s[i].price<<"\n";
			}
		}
};
int main() {
	int isbn,x;
	bool flag =false;
	book s[5];
	s[0].ciin(s,5);
menu:
	cout<<"which one ?\n"<<"1)sort by price  2)sort by name  3)delete by ISBN ";
	cin>>x;
	switch(x) {
		case 1:
			s[0].sortprice(s,5);
			s[0].print(s,5);
			break;
		case 2:
			s[0].sortname(s,5);
			s[0].print(s,5);
			break;
		case 3:
			cout<<"enter ISBN : ";
			cin>>isbn;
			flag=s[0].deleteISBN(s,5,isbn);
			if(flag==false)
				cout<<"not found";
			else {
				s[0].print(s,4);
			}
			break;
	}
	cout<<"1) go to menu  2)exit \n";
	cin>>x;
	if(x==1)
		goto menu;
	else
		return 0;
}
