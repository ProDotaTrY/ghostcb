#include "window.h"

void DEBUG_ui(const string &message);

CWindow::CWindow()
	: CWidget(0, true)
{
	// Initialize curses
	_window = initscr();
	refresh();

	_size.set(COLS, LINES);
	
	_widget = 0;

	start_color();

	uint k = 0;
	for(uint i = 0; i <= 7; i++)
	{
		for(uint j = 0; j <= 7; j++)
		{
			init_pair(k++, i, j);
		}
	}

	nodelay(_window, true);
	keypad(_window, true);
	cbreak();
	noecho();
	
	// Mouse
	mousemask(ALL_MOUSE_EVENTS, 0);
	mouseinterval(30);
	curs_set(0); // 0 = nothing, 1 = underline, 2 = block
}

CWindow::~CWindow()
{
	SafeDelete(_widget);

	// Exit curses
	endwin();
}

void CWindow::setWidget(CWidget *widget)
{
	_widget = widget;
	_widget->setParent(this);
	_widget->setSize(_size.width(), _size.height());
}

void CWindow::setSize(uint width, uint height)
{
	if(float(width)/float(height) <= 0.4f || height > 84 || width <= 40 || height <= 10)
		return;

	_size.set(width, height);

	resize_term(height, width);

	// Resize main widget too
	if(_widget)
		_widget->setSize(width, height);
}

void CWindow::setTitle(const string &title)
{
#ifdef __PDCURSES__
	PDC_set_title(title.c_str());
#endif
}

void CWindow::hide()
{
	hide_panel(_panel);
	_visible = false;

	// Hide subwidget too
	if(_widget)
		_widget->hide();
}

void CWindow::show()
{
	show_panel(_panel);
	_visible = true;

	// Show subwidget too
	if(_widget)
		_widget->show();
}

void CWindow::update()
{
	DEBUG_ui("CWindow::update");
	updateInput();

	if(_widget)
		_widget->update(_key);

	update_panels();
	doupdate();
}

void CWindow::updateInput()
{
	_key = wgetch(_window);

	updateMouse(_key);
}

void CWindow::updateMouse(int c)
{
#ifdef __PDCURSES__
	// Mouse position update
	//request_mouse_pos();
#endif
}

int CWindow::key()
{
	return _key;
}
