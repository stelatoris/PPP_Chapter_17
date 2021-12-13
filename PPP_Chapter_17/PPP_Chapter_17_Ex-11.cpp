//	PPP Chapter 17 Ex 10
//11. Complete the “list of gods” example from §17.10.1 and run it.

#include "std_lib_facilities.h"

class Link {
public:
	string value;
	Link(const string& v, Link* p = nullptr, Link* s = nullptr)
		: value{ v }, prev{ p }, succ{ s } { }

	Link* insert(Link* n); // insert n before this object
	Link* add(Link* n); // insert n after this object
	Link* erase(); // remove this object from list
	Link* find(const string& s); // find s in list
	const Link* find(const string& s) const; // find s in const list (see §18.5.1)

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
	n-> prev = prev; // this object’s predecessor becomes n’s predecessor
	prev = n; // n becomes this object’s predecessor
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

Link* Link::erase() // remove *p from list; return p’s successor
{
	if (this == nullptr) return nullptr;
	if (succ) succ-> prev = prev;
	if (prev) prev-> succ = succ;
	return succ;
}

Link* Link::find(const string& s) // find s in list;
// return nullptr for “not found”
{
	Link* p = this;
	while (p) {
		if (p-> value == s) return p;
		p = next();
	}
	return nullptr;
}

Link* Link::advance(int n) const // move n positions in list
// return nullptr for “not found”
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
		cout << p-> value;
		if (p = p-> next()) cout << ", ";
	}
	cout << " }";
}


int main()
try {

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

	return 0;
}

catch (exception& e) {
	cerr << "exception: " << e.what() << endl;
}
catch (...) {
	cerr << "exception\n";
}