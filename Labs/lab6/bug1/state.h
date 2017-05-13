
#ifndef STATE_H
#define STATE_H

/* your debug code here */


class state {
private:
	char *name;
	int pop;
public:
	void set_name(const char *);
	void display_pop();
	void set_pop(int);
	state();
	virtual ~state();
};

#else
/* your non-debug code here, if differences exist */

#endif /* STATE_H_ */
