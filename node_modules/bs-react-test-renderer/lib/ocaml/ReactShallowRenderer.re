type t;

external createRenderer :
  unit => t = "" [@@bs.val] [@@bs.module "react-test-renderer/shallow"];

external render :
  t => ReactRe.reactElement => option ReactRe.reactElement = "" [@@bs.send];

external getRenderOutput :
  t => option ReactRe.reactElement = "" [@@bs.send];

external unmount :
  t => unit = "" [@@bs.send];

let renderWithRenderer = render (createRenderer ());
