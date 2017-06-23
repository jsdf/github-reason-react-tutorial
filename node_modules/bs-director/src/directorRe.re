type t;

external makeRouter : Js.t {..} => t =
  "Router" [@@bs.module "director"] [@@bs.new];

external init : t => string => unit = "init" [@@bs.send];
