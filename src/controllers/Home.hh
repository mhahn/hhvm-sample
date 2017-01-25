<?hh // strict

namespace Sample;

use FredEmmott\HackRouter\UriPattern;
use FredEmmott\HackRouter\IncludeInUriMap;
use FredEmmott\HackRouter\SupportsGetRequests;
use Psr\Http\Message\ResponseInterface;

final class Home extends Controller implements IncludeInUriMap, SupportsGetRequests {
	public static function getUriPattern() : UriPattern {
		return (new UriPattern())->literal('/');
	}

	public async function getResponse() : Awaitable<ResponseInterface> {
		return Response::newEmpty()->withStatus(200);
	}
}
