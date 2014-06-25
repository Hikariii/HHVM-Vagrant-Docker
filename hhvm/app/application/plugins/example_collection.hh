<?hh // strict

class ExampleCollection
{
	protected Vector $vector;
	protected Set $set;
	protected Map $map;
	protected ImmVector $frozen;

    public function __construct() {
		$this->vector = Vector {1, 2, 3};
		$this->set = Set {"foo", "bar", "baz"};
		$this->map = Map { 1 => "hello", 2 => "world" , 3 => "baz"};
		$this->frozen = ImmVector{5,6};
	}
	
	public function __toString(): void {
		return var_export($this->vector, true) . "\n" .
			var_export($this->set, true) . "\n" .
			var_export($this->map, true) . "\n" .
			var_export($this->frozen, true);
	}
    
}
