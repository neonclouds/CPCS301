#include "book.h"


book::book(int Bookid2, string Title2, string Author2, string Category2) {
	bookid = Bookid2;
	title = Title2;
	author = Author2;
	category = Category2;
}

int book::getbookid() {
	return bookid;
}

string book::gettitle() {
	return title;
}
string book::getauthor() {
	return author;
}
string book::getcategory() {
	return category;
}