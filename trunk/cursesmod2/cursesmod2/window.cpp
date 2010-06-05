#include "window.h"

CWindow::CWindow()
	: CWidget(0, true)
{
	// Initialize curses
	_window = initscr();
	_panel = new_panel(_window);
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
	//noecho( );
	//cbreak( );
	
#ifdef __PDCURSES__
	// Mouse cursor
	mouse_on( ALL_MOUSE_EVENTS );
	mouseinterval( 50 );
	curs_set( 1 );	// 0 = nothing or 1 = underline or 2 = block
#endif
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
	if(float(width)/float(height) <= 0.4f || height > 84)
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
	updateInput();

	if(_widget)
		_widget->update();

	update_panels();
	doupdate();
}

void CWindow::updateInput()
{
	int c = wgetch(_window);

	updateMouse( c );
}

void CWindow::updateMouse(int c)
{
#ifdef __PDCURSES__
	// Mouse position update
	request_mouse_pos( );

	if( MOUSE_Y_POS != -1 )
		_mouseY = MOUSE_Y_POS;

	if( MOUSE_X_POS != -1 )
		_mouseX = MOUSE_X_POS;

	move( _mouseY, _mouseX );

	if( Mouse_status.changes == MOUSE_WHEEL_UP )
	{
	}
	else if( Mouse_status.changes == MOUSE_WHEEL_DOWN )
	{
	}
#endif
}
