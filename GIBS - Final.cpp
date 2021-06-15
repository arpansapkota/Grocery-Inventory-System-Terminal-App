#include <iostream>
#include <conio.h>
#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <cstring>

using namespace std;

class goods
{

   protected:
        int id;
        char name[10];
        int quantity;
        int mp;
        char expiry[10];
   public:
        void read();
        void label();
        void show();
        virtual void addnew(){};
        virtual void stat(){};
        virtual void edit(){};
        virtual void Delete(){};
        virtual void refill(){};
        virtual void sell_good(){};
		virtual void show_items(){};
		virtual void show_particular(int a){};
};

class manage:public goods
{
     friend class sell;
	 public:
	 	manage()
	 	{
	 		id=0;
			strcpy(name,"");
			quantity=0;
			mp=0;
			strcpy(expiry,"");
		 }

        void addnew();
        void transfer();
        void stat();
        void refill();
        void edit();
        void Delete();


};

class sell :public goods
{

	public:
		manage get_by_id(int search_id);
		void sell_good();
		void show_items();
		void show_particular(int);
		void reduce_quantity(int search_id, int reduce);



};

int menu(int a)//main menu
{
        int option;
        cout<<"======Grocery Inventory and Billing System========"<<endl;
        cout<<"||\t"<<ends<<"1.Selling mode"<<"\t\t\t\t"<<"||"<<endl;
        cout<<"||\t"<<ends<<"2.Managing mode"<<"\t\t\t"<<"||"<<endl;
        cout<<"||\t"<<ends<<"3.Exit"<<"\t\t\t\t\t"<<"||"<<endl;
        cout<<"=================================================="<<endl;
        cout<<"Enter 1 to go to selling mode 2 to managing mode 3 to exit"<<endl;
        cin>>option;
        return option;
}
int menu(char m)//selling menu
{
        int option;
        cout<<"======Grocery Inventory and Billing System========"<<endl;
        cout<<ends<<"1.Sell goods"<<endl;
        cout<<ends<<"2.Show goods"<<endl;
        cout<<ends<<"3.Find goods"<<endl;
        cout<<ends<<"4.Go to main menu"<<endl;
        cout<<"Enter option accordingly"<<endl;
        cin>>option;
        return option;
}
int menu(char m,int i)//Managing menu
{
        int option;
        cout<<"======Grocery Inventory and Billing System========"<<endl;
        cout<<ends<<"1.Edit items"<<endl;
        cout<<ends<<"2.Stats of all goods"<<endl;
        cout<<ends<<"3.Refill Stocks"<<endl;
        cout<<ends<<"4.Add new items"<<endl;
        cout<<ends<<"5.Delete items"<<endl;
        cout<<ends<<"6.Go to main menu"<<endl;
        cout<<"enter option accordingly"<<endl;
        cin>>option;
        return option;
}



int main()
{
    int option;
    char polar;

    goods *obj;
    manage objm;
    sell objs;

    	try
        {

        	char user[15];
        	int indx=0;
        	char password[10];


            cout<<"======Grocery Inventory and Billing System========"<<endl;
			cout <<"Enter username:";
			cin.get(user,15);
			cout<<"Password:";


            while (indx<10)
            {
            	password[indx]=getch();cout<<"*";
            	if (password[indx]==char(32)) break;
   				indx++;
            }
			if (!((stricmp(user,"Gaurav Karki")==0 && stricmp(password,"104 ")==0)||(stricmp(user,"Kushal Dura")==0 && stricmp(password,"110 ")==0)||(stricmp(user,"Arpan Sapkota")==0 && stricmp(password,"97 ")==0)||(stricmp(user,"Kisne Thapa")==0 && stricmp(password,"109 ")==0)))
			{
				throw 'a';
			}


		}

		catch (char a)
		{
			system("cls");
			cout<<"User name with this password does not exist";
			return 0;
		}


    while(true)
    {
        system("cls");
        option=menu(1);


        switch(option){

            case 1:
            		obj=&objs;
                    system("cls");
                    do{
                        option=menu('m');
                        if(option==4)
                            {

                                break;
                            }
                        switch (option)
                            {
                                case 1:
                                    obj->show_items();
                                	obj->sell_good();
                                    break;

                                case 2:
                                	obj->show_items();
                                    break;
                                case 3:
                                	int id_no;

                                	cout<<"Enter the id of the product"<<endl;
                                	cin>>id_no;
                                	obj->show_particular(id_no);
                                    break;
                                default:
                                    cout<<"Enter values from above"<<endl;
                            }
                    cout<<endl<<"Do you want to stay in this selling mode(y/n)"<<endl;
                    cin>>polar;

                    system("cls");

                    }while(polar=='Y'||polar=='y');

                    break;


        case 2:
                obj=&objm;
                system("cls");

                do{
                        option=menu('m',2);
                        if(option==6)
                            {
                                break;
                            }
                        switch (option)
                            {
                                case 1:
                                    obj->stat();
                                    obj->edit();
                                    break;

                                case 2:
                                    obj->stat();
                                    break;
                                case 3:
                                    obj->stat();
                                    obj->refill();
                                    break;
                                case 4:
                                    obj->stat();
                                    obj->addnew();
                                    break;
                                case 5:
                                    obj->stat();
                                    obj->Delete();
                                    break;
                                default:
                                cout<<"Enter values from above"<<endl;
                            }
                cout<<endl<<"Do you want to stay in managing mode(y/n)"<<endl;
                cin>>polar;

                system("cls");

             }while(polar=='Y'||polar=='y');

              break;

        case 3:
                system("cls");
                cout<<endl<<"thank you exitting........................................................"<<endl;
                return 0;

                break;

        default:
                cout<<"Syntax error enter valid  choice"<<endl;
                break;
        };//switch end
    }//end of while loop
    return 0;

}

void goods::read()
        {
            cout<<endl<<"Enter name of the goods:"<<endl;
            cin>>name;
            cout<<"Enter ID of the goods:"<<endl;
            cin>>id;
            cout<<"Enter quantity of the goods:"<<endl;
            cin>>quantity;
            cout<<"Enter marked price of the goods:"<<endl;
            cin>>mp;
            cout<<"Enter expiry  of the goods:[year-month-day]"<<endl;
            cin>>expiry;
        }
void goods::label()
        {
            cout<<"ID\t"<<ends<<ends;
            cout<<"Name\t\t"<<ends;
            cout<<"\tQuantity\t"<<ends;
            cout<<"Marked Price\t"<<ends;
            cout<<"Expiry date\t"<<ends;
        }
void goods::show()
        {
            cout<<endl<<endl;
            cout<<id<<"\t"<<ends;
            cout<<name<<"\t"<<ends;
            cout<<"\t\t"<<quantity<<"\t\t"<<ends;
            cout<<mp<<"\t\t"<<ends;
            cout<<expiry<<"\t\t"<<ends;
        }

void manage::addnew()
        {
            fstream file;
            manage obj;
            char polar='y';

            file.open("goods.dat",ios::out|ios::app|ios::binary);

            do
            {
                obj.read();
                file.write(reinterpret_cast<const char *>(&obj),sizeof(obj));
                cout<<"Press y to add again n to exit"<<endl;
                cin>>polar;
            }while(polar=='y'|polar=='Y');

            file.close();
        }

void manage::transfer()
        {
            fstream temp;
            fstream file;
            manage obj;

            file.open("goods.dat",ios::out|ios::binary);
            temp.open("temp.dat",ios::in|ios::app|ios::binary);

            file.seekp(0,ios::beg);
            temp.seekg(0,ios::beg);

            while(true)
            {
                temp.read(reinterpret_cast<char *>(&obj),sizeof(obj));
                if(temp.eof())
                {
                    cout<<"Opeartion Sucessfull"<<endl;
                    break;
                }
                file.write(reinterpret_cast<char *>(&obj),sizeof(obj));

            }

            file.close();
            temp.close();
        }

void manage::stat()
         {
            fstream file;
            manage obj;
            char polar;

            file.open("goods.dat",ios::in|ios::app|ios::binary);

            file.seekg(0,ios::beg);

            obj.label();
            //while hald last ko badi dekhayo
            while(true){

                file.read(reinterpret_cast<char *>(&obj),sizeof(obj));
                if(file.eof()){break;}//to fix showing last object two times
                obj.show();
                }

            file.close();
        }

void manage::refill()
        {
            fstream file;
            fstream temp;
            manage obj;
            manage tempobj;
            char polar;

            int tempid;
            int tempqy;

            cout<<endl;
            cout<<"enter id of the product to be refilled"<<endl;
            cin>>tempid;

            file.open("goods.dat",ios::in|ios::app|ios::binary);
            temp.open("temp.dat",ios::out|ios::binary);

            file.seekg(0,ios::beg);

            while(true)
            {
                file.read(reinterpret_cast<char *>(&obj),sizeof(obj));
                if(file.eof())
                {
                    cout<<"End of file reached"<<endl;
                    break;
                }
                else if(obj.id!=tempid)
                {
                    temp.write(reinterpret_cast<char *>(&obj),sizeof(obj));
                }
                else if(obj.id==tempid)
                {
                    cout<<"Present Quantity:"<<obj.quantity<<endl;
                    cout<<"Enter number to be added"<<endl;
                    cin>>tempqy;
                    tempobj=obj;
                    tempobj.quantity=tempqy+tempobj.quantity;
                    temp.write(reinterpret_cast<char *>(&tempobj),sizeof(tempobj));
                }
            }

            file.close();
            temp.close();

            transfer();
        }

void manage::edit()
        {
            fstream file;
            fstream temp;
            manage obj;
            manage tempobj;
            char polar;
            int tempid;

            cout<<endl;
            cout<<"enter id of the product to be edited"<<endl;
            cin>>tempid;

            file.open("goods.dat",ios::in|ios::app|ios::binary);
            temp.open("temp.dat",ios::out|ios::binary);
            file.seekg(0,ios::beg);

            while(true)
            {
                file.read(reinterpret_cast<char *>(&obj),sizeof(obj));
                if(file.eof())
                {
                    cout<<"End of file reached"<<endl;
                    break;
                }
                else if(obj.id!=tempid)
                {
                    temp.write(reinterpret_cast<char *>(&obj),sizeof(obj));
                }
                else if(obj.id==tempid)
                {
                    obj.label();
                    obj.show();
                    cout<<"will be edited."<<endl;
                    cout<<"Enter new edited:"<<endl;
                    obj.read();
                    temp.write(reinterpret_cast<char *>(&obj),sizeof(obj));
                }
            }

            file.close();
            temp.close();

            transfer();
        }

void manage::Delete()
        {
            fstream file;
            fstream temp;
            manage obj;

            char polar;
            int tempid;

            cout<<endl;
            cout<<"enter id of the product to be deleted"<<endl;
            cin>>tempid;

            file.open("goods.dat",ios::in|ios::app|ios::binary);
            temp.open("temp.dat",ios::out|ios::binary);

            file.seekg(0,ios::beg);

            while(true)
            {
                file.read(reinterpret_cast<char *>(&obj),sizeof(obj));
                if(file.eof())
                {
                    cout<<"End of file reached"<<endl;
                    break;
                }
                else if(obj.id!=tempid)
                {
                    temp.write(reinterpret_cast<char *>(&obj),sizeof(obj));
                }
                else if(obj.id==tempid)
                {
                    obj.label();
                    obj.show();
                    cout<<"will be deleted"<<endl;
                    cout<<"Press y to delete";
                    cin>>polar;
                    if(polar=='y'|polar=='Y')
                    {
                        continue;
                    }else {
                         temp.write(reinterpret_cast<char *>(&obj),sizeof(obj));
                        }
                }
            }

            file.close();
            temp.close();

            transfer();
        }

void sell::sell_good()
		{
			struct prod_info
			{
                int prod_id;
                char prod_name[10];
                int prod_quantity;
                int prod_mp;
                float prod_discount;
                float prod_price;
			};

			int n;//total items to be sold
			int count=0,id,i=0;

			float discount,price,total_price,vat;

			manage obj;
			struct prod_info *billitem;

			cout<<"Enter no. of items to sell"<<endl;
			cin>>n;

			if(n<0||n==0)
                {
                    cout<<"invalid number"<<endl;
                }else{

                    billitem=new struct prod_info[n];

                    while(i<n)
                    {

                        cout<<"Enter product id"<<endl;
                        cin>>id;

                        obj=get_by_id(id);

                        if (obj.id==0)
                        {
                            cout<<"ID not matched with any item";
                            continue;

                        }
                        cout<<"Enter quantity";
                        cin>>quantity;

                        if (quantity>obj.quantity)
                        {

                            cout<<"Sorry!!! Not  enough quantity";
                            i++;
                            //system("cls"); not enough quantity harauxa
                            continue;

                        }

                        cout<<"Enter discount rate for this item";
                        cin>>discount;

                        price=quantity*(obj.mp-((discount/100)*obj.mp));

                        total_price=total_price+price;


                        reduce_quantity(id,quantity);
                        billitem[count].prod_id=id;
                        strcpy(billitem[count].prod_name,obj.name);
                        billitem[count].prod_quantity=quantity;
                        billitem[count].prod_mp=obj.mp;
                        billitem[count].prod_discount=discount;
                        billitem[count].prod_price=price;
                        count++;
                        i++;

                    }//end of while loop
                system("cls");

                cout<<"======Grocery Inventory and Billing System========"<<endl<<endl;
                cout<<setw(20)<<setiosflags(ios::left)<<"S.NO.";
                cout<<setw(20)<<setiosflags(ios::left)<<"Product ID";
                cout<<setw(20)<<setiosflags(ios::left)<<"Product Name";
                cout<<setw(20)<<setiosflags(ios::left)<<"Quantity";
                cout<<setw(20)<<setiosflags(ios::left)<<"Marked Price";
                cout<<setw(20)<<setiosflags(ios::left)<<"Discount";
                cout<<setw(20)<<setiosflags(ios::left)<<"Price"<<endl;

                n=0;

                for (i=0;i<count;i++)
                {
                    cout<<setw(20)<<setiosflags(ios::left)<<++n;
                    cout<<setw(20)<<setiosflags(ios::left)<<billitem[i].prod_id;
                    cout<<setw(20)<<setiosflags(ios::left)<<billitem[i].prod_name;
                    cout<<setw(20)<<setiosflags(ios::left)<<billitem[i].prod_quantity;
                    cout<<setw(20)<<setiosflags(ios::left)<<billitem[i].prod_mp;
                    cout<<setw(20)<<setiosflags(ios::left)<<billitem[i].prod_discount;
                    cout<<setw(20)<<setiosflags(ios::left)<<billitem[i].prod_price<<endl<<endl;

                }

                delete []billitem;

                vat=((13.0/100)*total_price)+total_price;

                cout<<setw(15)<<setiosflags(ios::left)<<"Total price:"<<total_price<<ends;

                cout<<setw(20)<<setiosflags(ios::right)<<"VAT:13%"<<endl;
                cout<<setw(20)<<setiosflags(ios::left)<<"Total price with vat:"<<ends<<vat;
                cout<<endl;

            }//end of else


		}


void sell::show_particular(int search_id)
{
	fstream file;
    manage obj;

    file.open("goods.dat",ios::in|ios::binary);
    file.seekg(0,ios::beg);

	file.read(reinterpret_cast<char *>(&obj),sizeof(obj));

	obj.label();
	while(!file.eof())
    {
        if(obj.id==search_id)
        	{
                obj.show();
            }

        file.read(reinterpret_cast<char *>(&obj),sizeof(obj));
    }

    file.close();
}

void sell::show_items()
{
	fstream file;
    manage obj;

    file.open("goods.dat",ios::in|ios::binary);

	file.seekg(0,ios::beg);

	file.read(reinterpret_cast<char *>(&obj),sizeof(obj));

    obj.label();
	while(!file.eof())
    {
        obj.show();
        file.read(reinterpret_cast<char *>(&obj),sizeof(obj));
    }

    file.close();
    cout<<endl;
}
manage sell::get_by_id(int search_id)
{
    fstream file;
    manage obj;

    file.open("goods.dat",ios::in|ios::binary);
    file.seekg(0,ios::beg);

	while(!file.eof())
        {
            file.read(reinterpret_cast<char *>(&obj),sizeof(obj));
            if(obj.id==search_id)
                {
                    file.close();
                	return obj;
                }

        }
	file.close();

	return manage();

}

void sell::reduce_quantity(int search_id, int reduce)
        {
            fstream file;
            fstream temp;
            manage obj;




            file.open("goods.dat",ios::in|ios::app|ios::binary);
            temp.open("temp.dat",ios::out|ios::binary);
            file.seekg(0,ios::beg);

            while(true)
            {
                file.read(reinterpret_cast<char *>(&obj),sizeof(obj));
                if(file.eof())
                {

                    break;
                }
                else if(obj.id!=search_id)
                {
                    temp.write(reinterpret_cast<char *>(&obj),sizeof(obj));
                }
                else if(obj.id==search_id)
                {



                    obj.quantity=obj.quantity-reduce;
                    temp.write(reinterpret_cast<char *>(&obj),sizeof(obj));
                }
            }

            file.close();
            temp.close();

          obj.transfer();
        }
