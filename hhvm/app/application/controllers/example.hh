<?hh // strict

class Example extends Controller {
	
	public function index(): void {
		$this->loadPlugin('example_collection.hh');
		$template = $this->loadView('example');
        $template->set('vardump', new ExampleCollection());
		$template->render();
	}
    
}
