<?hh // strict
/**
 * This file is generated. Do not modify it manually!
 *
 * To re-generate this file run /var/www/bin/build.hh
 *
 *
 * @generated SignedSource<<835ad86bd79c34040048e2eaa49f01df>>
 */
namespace Sample;

final class Router
  extends \FredEmmott\HackRouter\BaseRouter<classname<\Sample\Controller>> {

  <<__Override>>
  final public function getRoutes(
  ): ImmMap<\FredEmmott\HackRouter\HttpMethod, ImmMap<string, classname<\Sample\Controller>>> {
    $get = ImmMap {
      '/' => \Sample\Home::class,
    };
    return ImmMap {
      \FredEmmott\HackRouter\HttpMethod::GET => $get,
    };
  }
}
