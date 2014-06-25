<?hh // strict

class Main extends Controller {
	
	public function index(): void {
		$template = $this->loadView('main_view');
        $template->set('word','world.');
		$template->render();
	}
    
}
