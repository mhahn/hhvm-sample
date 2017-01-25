<?hh // strict

namespace Sample;

use Psr\Http\Message\ResponseInterface;
use Psr\Http\Message\ServerRequestInterface;
use Zend\Diactoros\Response\SapiEmitter;

use Sample\Router;
use Sample\Controller;

final class App {
	public static async function respondTo(
		ServerRequestInterface $request
	) : Awaitable<void> {
		var_dump($request);
		$response = await self::getResponseForRequest($request);
		/* HH_IGNORE_ERROR[2049] no HHI for Diactoros */
		(new SapiEmitter())->emit($response);
	}

	private static function routeRequest(
		ServerRequestInterface $request,
	) : (classname<Controller>, ImmMap<string, string>) {
		// TODO: error handling
		return (new Router())->routePsr7Request($request);
	}

	public static async function getResponseForRequest(
		ServerRequestInterface $request
	) : Awaitable<ResponseInterface> {
		// TODO: error handling
		list($controller, $vars) = self::routeRequest($request);
		return await (new $controller($vars, $request))->getResponse();
	}
}