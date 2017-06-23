type t;

external create :
  ReactRe.reactElement => t = "" [@@bs.val] [@@bs.module "react-test-renderer"];

external toJSON :
  t => Js.Json.t = "" [@@bs.send];
