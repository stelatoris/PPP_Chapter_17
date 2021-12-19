//	PPP Chapter 17 Ex 13
// 
//	13. Modify the Link class from §17.10.1 to hold a value of a struct God.
//	struct God should have members of type string : name, mythology, vehicle,
//	and weapon.For example, God{ "Zeus", "Greek", "", "lightning" }
//	and God{ "Odin", "Norse", "Eight-legged flying horse called Sleipner",
//	"Spear called Gungnir" }. Write a print_all() function that lists gods with
//	their attributes one per line.Add a member function add_ordered() that
//	places its new element in its correct lexicographical position.Using the
//	Links with the values of type God, make a list of gods from three mythologies;
//	then move the elements(gods) from that list to three lexicographically
//	ordered lists — one for each mythology.

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
	const Link* find(const string& s) const; // find s in const list (see §18.5.1)

	Link* advance(int n) const; // move n positions in list
	Link* add_ordered(Link* n);	// order in lexicographical order

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
		if (p->god.name == s) return p;
		p = p->succ;
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

Link* Link::add_ordered(Link* n)
{
	Link* p = this;

	while (p) {

		if (n->god.name < p->god.name) {			// if n is smaller than this(p)
			if (p->prev == nullptr) {				// if this(p) is 1st link
				p=p->insert(n);
				return p;
			}
			else p = p->advance(-1);
		}
		else if (p->god.name < n->god.name) {		// if n is larger than this(p)
			if (p->succ == nullptr) {
				p=p->add(n);
				return p;
			}
			else if (n->god.name < p->succ->god.name) {
				p = p->add(n);
				return p;
			}
			else p = p->advance(1);
		}
	}
}

void lexicograph_order(Link* in, Link* out)
{
	while (in) {	// go back to 1st Link
		if (!in->previous()) break;
		in = in->previous();
	}

	string myth = out->god.mythology;	//which mythology to search for?
	
	while (in) {
		if (in->god.mythology == myth) {	// extract only gods from specified mythology
			Link* s = out->find(in->god.name);
			if (s==nullptr){
				Link* p = in;				// copy link to temp
				in = in->erase();			// delete link from original list
				out = out->add_ordered(p);	// add the link from temp
			}
			else if (s->god.name == in->god.name) {
				cout << in->god.name << " already entered." << '\n';
			}						
		}
		else in = in->next();				// keep going through the list
	}
}

void print_all(Link* p)
{
	while (p) {
		if (!p->previous()) break;
		p = p->previous();
	}
	
	if (p->god.mythology == "Norse") cout << "Norse gods:\n";
	else if(p->god.mythology == "Roman") cout << "Roman gods:\n";
	else if (p->god.mythology == "Greek") cout << "Greek gods:\n";
	else {}

	while (p) {		
		cout <<'-' << p->god.name << ',' << p->god.mythology
			<< ',' << p->god.vehicle << ',' << p->god.weapon;
		if (p = p->next()) cout << '\n';
	}
}

int main()
try {

	// name{ n }, mythology{ m }, vehicle{ v }, weapon{ w } { }
	Link* gods = new Link{ "Hades ","Greek","","The Helm of Darkness" };
	gods = gods->add(new Link{ "Poseidon ","Greek","The Chariot of the Sea","The Trident of Poseidon" });	
	gods = gods->add(new Link{ "Saturn ","Roman","","Scythe" });
	gods = gods->add(new Link{ "Aphrodite","Greek","","Cestus " });
	gods = gods->add(new Link{ "Odin","Norse","Eight-legged flying horse, Sleipnir","Gungnir the spear" });
	gods = gods->add(new Link{ "Freya ","Norse","cats of Freya","Dainsleif (sword)" });
	gods = gods->add(new Link{ "Jupiter ","Roman","","Lightning Bolt" });
	gods = gods->add(new Link{ "Heimdall","Norse","","Gjallarhorn the Yelling Horn" });
	gods = gods->add(new Link{ "Vidar","Norse","","Vidar's Shoes" });
	gods = gods->add(new Link{ "Ullr ","Norse","","Arrow" });
	gods = gods->add(new Link{ "Athena","Greek","","The Aegis" });
	gods = gods->add(new Link{ "Juno","Roman","Cart","Spear" });
	gods = gods->add(new Link{ "Minerva","Roman","","Spear" });
	gods = gods->add(new Link{ "Mars","Roman","","Spear" });
	

	//print_all(gods);

	Link* norse_gods = new Link{ "Thor","Norse","Chariot of Thunder","Hammer" };
	Link* greek_gods= new Link{ "Zeus ","Greek","","Thunderbolts" };
	Link* roman_gods=new Link{ "Apollo","Roman","Sun Chariot","Silver Bow and Arrow" };

	lexicograph_order(gods, greek_gods);
	lexicograph_order(gods, norse_gods);
	lexicograph_order(gods, roman_gods);
	
	print_all(greek_gods);
	cout << '\n';
	print_all(norse_gods);
	cout << '\n';
	print_all(roman_gods);
	cout << '\n';

	return 0;
}

catch (exception& e) {
	cerr << "exception: " << e.what() << endl;
}
catch (...) {
	cerr << "exception\n";
}