<?hh // strict

namespace Sample;

use Psr\Http\Message\ResponseInterface;

final class Response {
	public static function newEmpty() : ResponseInterface {
		/* HH_IGNORE_ERROR[2049] no HHI for Diactoros */
		return new \Zend\Diactoros\Response();
	}

	public static function newWithStringBody(string $body) : ResponseInterface {
		/* HH_IGNORE_ERROR[2049] no HHI for Diactoros */
		$stream = new \Zend\Diactoros\Stream('php://temp', 'wb+');
		$stream->write($body);
		return static::newEmpty()->withBody($stream);
	}
}