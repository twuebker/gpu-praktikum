#include <string>
#include <SDL2/SDL.h>

namespace asteroids
{

/***
 *	Represents the main window of the game.
 */
class MainWindow
{
public:

	/***
	 * Creates a main window with given \ref title, width \ref w and height \ref h
	 *
	 * @param title		Title of the window
	 * @param w			Width
	 * @param h			Height
	 */
	MainWindow(std::string title, int w, int h);

	/***
	 * Destructor.
	 */
	~MainWindow();

	/***
	 * Handles user events and renders the current level.
	 */
	void run();

	/***
	 * Sets the level to render.
	 */
	void setLevel(Level* level);


	/***
	 * Gets the current SDL renderer
	 */
	SDL_Renderer* getRenderer();

private:

	/// Initializes all needed SDL resources
	void initSDL();

	/// Quits SDL and frees all resources
	void quitSDL();

	/// SDL renderer struct
	SDL_Renderer* 		m_renderer;

	/// SDL main window struct
	SDL_Window*			m_window;

	/// Window width
	int					m_width;

	/// Window height
	int					m_height;
};

} /* namespace jumper */

#endif /* SRC_MAINWINDOW_HPP_ */
