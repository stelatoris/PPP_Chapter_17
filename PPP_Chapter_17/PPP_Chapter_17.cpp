//	PPP Chapter 17 Ex 13
// 
//	13. Modify the Link class from �17.10.1 to hold a value of a struct God.
//	struct God should have members of type string : name, mythology, vehicle,
//	and weapon.For example, God{ "Zeus", "Greek", "", "lightning" }
//	and God{ "Odin", "Norse", "Eight-legged flying horse called Sleipner",
//	"Spear called Gungnir" }. Write a print_all() function that lists gods with
//	their attributes one per line.Add a member function add_ordered() that
//	places its new element in its correct lexicographical position.Using the
//	Links with the values of type God, make a list of gods from three mythologies;
//	then move the elements(gods) from that list to three lexicographically
//	ordered lists � one for each mythology.

#include "std_lib_facilities.h"

class Link {
public:	
	Link(string n, string m, string v, string w, Link* p = nullptr, Link* s = nullptr)
		: god{ n, m, v, w }, prev{ p }, succ{ s } { }

	struct God {
		God(string n, string m, string v, string w)
			: name{ n }, mythology{ m }, vehicle{ v }, weapon{ w } { }

		string name;
		string mythology;
		string vehicle;
		string weapon;
	};	

	God god;

	Link* insert(Link* n); // insert n before this object
	Link* add(Link* n); // insert n after this object
	Link* erase(); // remove this object from list
	Link* find(const string& s); // find s in list
	const Link* find(const string& s) const; // find s in const list (see �18.5.1)

	Link* advance(int n) const; // move n positions in list

	Link* next() const { return succ; }
	Link* previous() const { return prev; }

private:
	Link* prev;
	Link* succ;
};

Link* Link::insert(Link* n) // insert n before this object; return n
{
	if (n == nullptr) return this;
	if (this == nullptr) return n;
	n-> succ = this; // this object comes after n
	if (prev) prev-> succ = n;
	n-> prev = prev; // this object�s predecessor becomes n�s predecessor
	prev = n; // n becomes this object�s predecessor
	return n;
}

Link* Link::add(Link* n) // insert n after p; return n
{
	if (n == nullptr) return this;
	if (this == nullptr) return n;
	n -> prev = this; // this object comes before n
	if (succ) succ->prev = n;
	n->succ = succ;	//this objects successor becomes n's successor
	succ = n;
	return n;
}

Link* Link::erase() // remove *p from list; return p�s successor
{
	if (this == nullptr) return nullptr;
	if (succ) succ-> prev = prev;
	if (prev) prev-> succ = succ;
	return succ;
}

Link* Link::find(const string& s) // find s in list;
// return nullptr for �not found�
{
	Link* p = this;
	while (p) {
		if (p->god.name == s) return p;
		p = next();
	}
	return nullptr;
}

Link* Link::advance(int n) const // move n positions in list
// return nullptr for �not found�
// positive n moves forward, negative backward
{
	Link* p = const_cast<Link*>(this);
	if (this == nullptr) return nullptr;
	if (0 < n) {
		while (n--) {
			if (succ == nullptr) return nullptr;
			p = p-> succ;
		}
	}
	else if (n < 0) {
		while (n++) {
			if (p-> prev == nullptr) return nullptr;
			p = p-> prev;
		}
	}
	return p;
}

void print_all(Link* p)
{
	cout << "{ ";
	while (p) {
		cout << p->god.name;
		if (p = p-> next()) cout << ", ";
	}
	cout << " }";
}


int main()
try {

	/*
	Link* norse_gods = new Link{ "Thor" };
	norse_gods = norse_gods-> insert(new Link{ "Odin" });
	norse_gods = norse_gods-> insert(new Link{ "Zeus" });
	norse_gods = norse_gods-> insert(new Link{ "Freia" });

	Link* greek_gods = new Link{ "Hera" };
	greek_gods = greek_gods-> insert(new Link{ "Athena" });
	greek_gods = greek_gods-> insert(new Link{ "Mars" });
	greek_gods = greek_gods-> insert(new Link{ "Poseidon" });

	Link* p = greek_gods-> find("Mars");
	if (p) p-> value = "Ares";

	Link* p2 = norse_gods-> find("Zeus");
	if (p2) {
		if (p2 == norse_gods) norse_gods = p2-> next();
		p2-> erase();
		greek_gods = greek_gods-> insert(p2);
	}

	print_all(norse_gods);
	cout << "\n";
	print_all(greek_gods);
	cout << "\n";
	*/

	return 0;
}

catch (exception& e) {
	cerr << "exception: " << e.what() << endl;
}
catch (...) {
	cerr << "exception\n";
}