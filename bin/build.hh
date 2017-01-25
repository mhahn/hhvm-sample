<?hh

require_once(__DIR__.'/../vendor/hh_autoload.php');

use \FredEmmott\HackRouter\Codegen;

Codegen::forTree(
	__DIR__.'/../src/',
	shape(
		'controllerBase'	=> \Sample\Controller::class,
		'router'			=> shape(
			'abstract' 	=> false,
			'file' 		=> __DIR__.'/../src/Router.hh',
			'class' 	=> 'Router',
			'namespace' => 'Sample',
		)
	),
)->build();
