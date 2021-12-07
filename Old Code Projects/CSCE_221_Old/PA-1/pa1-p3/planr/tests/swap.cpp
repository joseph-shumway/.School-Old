#include "gtest/gtest.h"
#include "Collection.h"
#include "Jeans.h"
#include "Stress_ball.h"

using namespace std;

TEST(COLLECTION, SWAP)
{
   {
        cout<<"Create a collection for Stress_ball."<<endl;
        Collection<Stress_ball,Stress_ball_colors,Stress_ball_sizes> c1;
        cout<<"Inserting 5 Stress_balls."<<endl;    
        c1.insert_item(Stress_ball(Stress_ball_colors::red,Stress_ball_sizes::medium));
        c1.insert_item(Stress_ball(Stress_ball_colors::green,Stress_ball_sizes::small));
        c1.insert_item(Stress_ball(Stress_ball_colors::blue,Stress_ball_sizes::large));
        c1.insert_item(Stress_ball(Stress_ball_colors::yellow,Stress_ball_sizes::medium));
        c1.insert_item(Stress_ball(Stress_ball_colors::red,Stress_ball_sizes::small));
         cout<<"Number of Stress_balls successfully inserted: "<<c1.total_items() <<endl;        
        cout<<"Create another collection for Stress_ball."<<endl;
        Collection<Stress_ball,Stress_ball_colors,Stress_ball_sizes> c2;
        cout<<"Inserting 3 Stress_balls."<<endl; 
        c2.insert_item(Stress_ball(Stress_ball_colors::red,Stress_ball_sizes::medium));
        c2.insert_item(Stress_ball(Stress_ball_colors::green,Stress_ball_sizes::small));
        c2.insert_item(Stress_ball(Stress_ball_colors::blue,Stress_ball_sizes::large));
        cout<<"Number of Stress_balls successfully inserted: "<<c2.total_items() <<endl;        
        cout<<"\nBefore swapping (number of items):\n Collection 1: "<<c1.total_items()<<"\n Collection 2: "<<c2.total_items()<<endl<<endl;
        cout<<"Swapping collections"<<endl;
        swap(c1,c2);
        cout<<"\nAfter swapping (number of items):\n Collection 1: "<<c1.total_items()<<"\n Collection 2: "<<c2.total_items()<<endl;
        ASSERT_EQ(c1.total_items(),3);
        ASSERT_EQ(c2.total_items(),5);
}
{
  cout<<"\nCreate a collection for Jeans."<<endl;
     Collection<Jeans,Jeans_colors,Jeans_sizes> c;
       cout<<"Inserting 5 Jeans."<<endl;    
        c.insert_item(Jeans(Jeans_colors::white,Jeans_sizes::medium));
        c.insert_item(Jeans(Jeans_colors::black,Jeans_sizes::small));
        c.insert_item(Jeans(Jeans_colors::blue,Jeans_sizes::large));
        c.insert_item(Jeans(Jeans_colors::black,Jeans_sizes::medium));
        c.insert_item(Jeans(Jeans_colors::white,Jeans_sizes::small));
        cout<<"Number of Jeans successfully inserted: "<<c.total_items() <<endl;        
        cout<<"Create another collection for Jeans."<<endl;
        Collection<Jeans,Jeans_colors,Jeans_sizes> c1;
        cout<<"Inserting 4 Jeans."<<endl; 
        c1.insert_item(Jeans(Jeans_colors::grey,Jeans_sizes::small));
        c1.insert_item(Jeans(Jeans_colors::blue,Jeans_sizes::medium));
        c1.insert_item(Jeans(Jeans_colors::white,Jeans_sizes::medium));
        c1.insert_item(Jeans(Jeans_colors::grey,Jeans_sizes::large));
         cout<<"Number of Jeans successfully inserted: "<<c1.total_items() <<endl;        
        cout<<"\nBefore swapping (number of items):\n Collection 1: "<<c.total_items()<<"\n Collection 2: "<<c1.total_items()<<endl<<endl;
        cout<<"Swapping collections"<<endl;
        swap(c,c1);
         cout<<"\nAfter swapping (number of items):\n Collection 1: "<<c.total_items()<<"\n Collection 2: "<<c1.total_items()<<endl;
        ASSERT_EQ(c.total_items(),4);
        ASSERT_EQ(c1.total_items(),5);
}
}