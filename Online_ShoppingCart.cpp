#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <cstring>
#include <algorithm>

using namespace std;

class Abstract
{
	public:
	virtual void display() = 0;
	//virtual string get_name();
};

class products : public Abstract 
{
    private:
    std::string p_name;
    double p_cost;
    public:
    
   
    products()
    {}
    
    products(std::string name, double cost)
    {
        p_name = name;
        p_cost = cost;
       }
    
    double getprice()
    {
        return p_cost;
    }
    
    string get_name()
    {
        return p_name;
    }
    
    ~products(){
    }
    
    void display()
    {}
};


int find_index(vector <products> & product_index, products product_search)
{
    int start = 0;
    int end = product_index.size();
    for ( start; start < end ; start++)
    
    {
        if(product_index[start].get_name() == product_search.get_name())
            {
                return start;
            }
    }
      
    return -1;
}


products *a[] = {0};  // Declare the product prointer as global, to access by all the class, otherwise segmentation fault will come


class shopping_cart
{
    vector <products> product_cart;
    public:	
		    shopping_cart()
		    {
		    }	
		void fun_add(products* product_add,int count)
		{
		   int i = 0;
		   while(i < count)
		    {
			     product_cart.push_back(*product_add);  
			     i++;
		    }
		    cout << "Product_add :"<<i<<endl;	    
		}
	
		void fun_remove(products* product_remove)
		{
		    if(!product_cart.empty())
		    {
    		   	int temp = find_index(product_cart,*product_remove);
    		    
	    		    if (temp != -1)
	    		    {
	    		        auto index = product_cart.begin() + temp;
	    		        product_cart.erase(index);
	    		    }
		    }
		   else
		        cout << "The cart is already empty you can't remove"<<endl;
		        
		        
		  
	    }
	
		double fun_cal_cost()
		{
		  double cost = 0.0;
		  if(product_cart.size() != 0)
		  
		  {
	    		  for (auto product_cost : product_cart)
	    		  {
	    		      cost += product_cost.getprice();
	    		      
	    		  }
		  }
		  
		  else
		  {
		      cout << "Cart is empty"<< endl;
		      return cost;
		      
		  }
		   return cost; 
		    cout<<"\n"<<endl;
		   
		}
		
	
	
	
	int getsize()
	{
	
	return product_cart.size();
	
	}
	
	 std::string get_name(int i)
	 {
	 	return product_cart[i].get_name();
	 }
		
	 double getprice(int i)
	 {
	 	
		return product_cart[i].getprice();
		      
		  
	}
	
	~shopping_cart()
	{
	}
	
	 void display()   // Shopping Cart class is not inheriting the Abstract class hence if it is not used the function is not a problem
    {}   
};


int show_products()
{
	std::ifstream file_data;
	std::string line;
	unsigned int inc=0;
	file_data.open("Data.csv",std::ios::in);
	if(file_data.fail())
	{
		cerr << "Problem Opening file" << endl;
	return -1;
	}
	
	while(getline(file_data,line,'\n'))
	{	
		++inc;
		cout << inc << " "<< line << endl;	
	}
	
	file_data.close();
	return 0;
}

int find_the_product(std::string string_match)
{
	
	std::ifstream file_data;
	std::string line;
	file_data.open("Data.csv",std::ios::in);
	if(file_data.fail())
	{
		cerr << "Problem Opening file" << endl;
	return -1;
	}
	line = "";
	int index = 0;
	    while (getline(file_data,line))
	    {
	    		
		    string product_name;
		    double price;
		    string tempString;
		    
		    stringstream inputString(line);
		    
		    getline(inputString, product_name,',');
		
		    product_name.erase(remove(product_name.begin(),product_name.end(),'"'),product_name.end());
		    
		    cout << index << endl;
		    tempString = "";
		    
		    getline(inputString,tempString);
		    price = atof(tempString.c_str());
		    line = "";  
		    index++;
		    if(string_match.compare(product_name) == 0)
		    {
		    
		    	file_data.close();
		    	return index-1;
		    }
	    }
	  
	    file_data.close();
	    return -1;
	    
}



void write_to_file(int i,shopping_cart &shop_cart)
{
	std::ofstream out_file("shooping_result.txt",std::ios::app);
	if (!out_file.is_open())
		{
		
		cerr << "Could not open the file";
			
		}
	else
	
	
	out_file << shop_cart.get_name(i) << "   "<< shop_cart.getprice(i); 
	out_file << "\n";
	
	
	out_file.close();

}

int main()
{
    
    shopping_cart cart;
    
    std::string product_name;
    
    int count = 0;
    
    int index = -1;   
     
    int i = 0;
    
    int number = 0;
    
    double price = 0.0;
  
  std::ifstream file_data;
	std::string line;
	file_data.open("Data.csv",std::ios::in);
	if(file_data.fail())
	{
		cerr << "Problem Opening file" << endl;
	return -1;
	}
	line = "";
    		
	    while (getline(file_data,line))
	    {
		    string product_name;
		    double product_price;
		    string tempString;
		    
		    stringstream inputString(line);
		    
		    getline(inputString, product_name,',');
		    	    
		    tempString = "";
		    
		    getline(inputString,tempString);
		    product_price = atof(tempString.c_str());
		    line = "";
		    a[i]=new products {product_name,product_price};
		    i++;
	    
	    }
	    file_data.close();
	    
	    
    
    
    cout << "\n\n\nThe products available for customer " << endl;
    
     if (show_products() != 0)
    {
    	cout << "Enter the correct file path" << endl;
    }
while(1)
{   
cout << "Eneter the number for operation 1: Add to cart , 2: Remove from cart , 3: Check the price of the cart , 4 : End the process ::";
cin >> number;
switch(number)
{
	case 1:

	    index = -1;
	    cout << "\n\nCustomer enter the choice of the product add to cart and count " << endl;
	    
	    cout << "Enter the name of the product :: ";
	    cin >> product_name;
	    
	    while (index <= -1 )
	    {
		    index = find_the_product(product_name);   // Get the price of the product name that entered
		    cout << "index value " << index << endl;
		    if ( index > -1 )
		    {
		    	 
		    	break;
		    	
		    	}
		    cout << "Please enter the valid product name :: ";
		    cin >> product_name;
		    
		    
	    }
	    
	    
	    
	    cout << "Enter the count of the product :: ";
	    cin >> count;
	    while(count <= 0)
	    {
	    cout << "Enter the count of the product greater than 0 :: " ;
	    cin >> count;
	    }
	    
	    
	    cart.fun_add(a[index],count);
	    
	    price=cart.fun_cal_cost();
	   
	    cout << "Total price of cart " << price << endl;
		break;

	case 2:
		index = -1;
	    cout << "\n\nCustomer enter the choice of the product to remove from cart " << endl;
	    
	    cout << "Enter the name of the product :: ";
	    cin >> product_name;
	    
	    while (index <= -1 )
	    {
		    index = find_the_product(product_name);   // Get the price of the product name that entered
		    cout << "index value " << index << endl;
		    if ( index > -1 )
		    {
		    	 
		    	break;
		    	
		    	}
		    cout << "Please enter the valid product name :: ";
		    cin >> product_name;
		    
		    
	    }
	    
	    cart.fun_remove(a[index]);
		break;	
		
	case 3 :
		price=cart.fun_cal_cost();
	   
	    cout << "Total price of cart " << price << endl;

	}

     if (number == 4)
     {
     cout << "Cart size "<< cart.getsize() << endl;
     std::ofstream out_file("shooping_result.txt");
     out_file.close();
     cout << "";
     for ( int i =0; i < cart.getsize()  ; i++)
     {
     	write_to_file(i,cart);
     
     }
     out_file.open("shooping_result.txt",std::ios::app);
	if (!out_file.is_open())
		{
		
		cerr << "Could not open the file";
			
		}
	else
     out_file << "Total Price of Shopping Rs :" ;
     out_file << cart.fun_cal_cost();
     out_file.close();
     break; 
     }
     	
}

return 0;  
}



