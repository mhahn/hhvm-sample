<?hh // strict

namespace Sample;

use FredEmmott\HackRouter\RequestParameters;
use FredEmmott\HackRouter\HasUriPattern;
use FredEmmott\HackRouter\GetFastRoutePatternFromUriPattern;
use FredEmmott\HackRouter\GetUriBuilderFromUriPattern;
use Psr\Http\Message\ResponseInterface;
use Psr\Http\Message\ServerRequestInterface;

<<__ConsistentConstruct>>
abstract class Controller implements HasUriPattern {
	use GetFastRoutePatternFromUriPattern;
	use GetUriBuilderFromUriPattern;

	private RequestParameters $parameters;

	public function __construct(
		ImmMap<string, string> $parameters,
		private ServerRequestInterface $request,
	) {
		$combined_parameters = $parameters->toMap();
		foreach ($request->getQueryParams() as $key => $value) {
			if (is_array($value)) {
				continue;
			}
			$combined_parameters[(string) $key] = (string) $value;
		}

		$this->parameters = new RequestParameters(
			static::getUriPattern()->getParameters(),
			ImmVector { },
			$combined_parameters->immutable(),
		);
	}

	abstract public async function getResponse() : Awaitable<ResponseInterface>;
}
