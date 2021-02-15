#include "MyList.h"

//int MyList::size=0;

Element::Element(int val)
{
	data=val;
	next=nullptr;
}
MyList::MyList()
{
	head=nullptr;
	tail=nullptr;
	_size=0;
}
MyList::MyList(int x)
{
	_size=x;
  Element *temp=head->next;
	head=new Element(0);
	head->next=new Element(1);
	head->next->next=new Element(2);
	tail =head->next->next;


}

MyList::MyList(MyList &srcList)
{

}

MyList::MyList(MyList &&srcList)
{
	
}

int MyList::val()
{

}
void MyList::clear()
{	

		if(head==tail)
		{
			delete head;
		}
		Element *temp=head;

		while(temp!=tail)
		{
		delete temp; 
		temp=temp->next;
		}
		delete tail;
		delete head;
		delete temp;
		tail->next=nullptr;

	}

}
int MyList::empty()
{
	if (_size==0)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

void MyList::print()
{
	if(empty())
	{
		cout<<"["<<" "<<"]";
		return;

	}
	cout<<"[";
	MyList *temp=head;
	if(head != nullptr)
	{
		while(temp != nullptr)
		{
			cout<<temp->data;
			temp=temp->next;
		}
	}
	cout<<"]";
}
int MyList::size()
{
	return _size;
}