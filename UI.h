#pragma once
#include "Service.h"

class UI {
private:
	ServiceRepoTemplate serv;
	void add_ui();
	void del_ui();
	void update_ui();
	void show_all();
public:
	UI();
	UI(ServiceRepoTemplate&);
	void showUI();
	~UI();
};