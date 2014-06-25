<?hh // strict

class Example extends Controller {
	
	public function index(): void {
		$this->loadPlugin('example_collection');
		$template = $this->loadView('main_view');
        $template->set('vardump', new ExampleCollection());
		$template->render();
	}
    
}
