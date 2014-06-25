<?hh // strict

class View {

	private $pageVars = array();
	private $template;

	public function __construct(string $template): void {
		$this->template = APP_DIR .'views/'. $template .'.php';
	}

	public function set(string $var, mixed $val): void {
		$this->pageVars[$var] = $val;
	}

	public function render(): void {
		//extract($this->pageVars);
        $var = $this->pageVars;
		ob_start();
		include($this->template);
		echo ob_get_clean();
	}
    
}