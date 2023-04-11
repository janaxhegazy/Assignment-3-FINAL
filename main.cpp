//
//  main.cpp
//  assignment 3
//
//  Created by jana hegazy on 23/03/2023.

#include"Person.hpp"
#include"Queue.hpp"
#include"Customer.hpp"
#include"Mechanics.hpp"


const int MAXnum = 4;
const int CUSTnum = 5;
int main()
{
    

    Mechanic mechanics[MAXnum];
    mechanics[0]=Mechanic("Khaled", 1, 20);
    mechanics[1]=Mechanic("Ahmed", 2, 40);
    mechanics[2]=Mechanic("Mahmoud", 3, 60);
   
    Customer customers[CUSTnum];
    for (int i = 0; i < CUSTnum; i++)
    {
        int num,h,m;
        string name, ID;
        cout << "Please enter the customer information such as name age id appointment time(hours min):  ";
        cin >> name >> num >> ID>>h>>m;
        Appointment temp(h, m);
        customers[i].Customer::Customer(name, ID, num,"",temp);
        int x=0;
        for (x = 0; x < MAXnum; x++)
        {
            if (mechanics[x].IsAvailable(temp))
                break;
        }
        if (x == MAXnum)
        {
            Appointment temp2(-1, -1);
            customers[i].setApp(temp2);
        }
        else
        {
            for (int y = i % MAXnum; y > -3; y++)
            {
                if (mechanics[y].IsAvailable(temp))
                {
                    customers[i].setMID(mechanics[y].getID());
                    mechanics[y].setApp(temp);
                    break;
                }
            }
        }
    }
    Queue<Customer> jana(CUSTnum);
    for (int x = 0; x < CUSTnum; x++)
    {
            for (int j = x + 1; j < CUSTnum; j++)
            {
                if (customers[j] < customers[x])
                {
                    Customer temp = customers[j];
                    customers[j] = customers[x];
                    customers[x] = temp;
                }
            }
            jana.push(customers[x]);
    }

    for (int i = 0; i < CUSTnum; i++) // FINALLY FIXED IT YAY
        {
            string Mname=" ";
            Customer jana1 = jana.pop();
        
            
            for (int i = 0; i < MAXnum; i++)
            {
                if (jana1.getMID() == mechanics[i].getID())
                    Mname= mechanics[i].getName();
            }
            if (Mname == " ")
                cout << "the customer " << jana1.getName() << "'s request for appointnment has been unfortunately declined due to the unavalibality of mechanics. TRY AGAIN LATER! " << endl;
            else
            cout << "the customer " << jana1.getName() << "'s apointment is at " <<  jana1.getApp().hours << ":" << jana1.getApp().min << "with the mechanic " <<Mname<< endl;
        }
    return 0;
}

