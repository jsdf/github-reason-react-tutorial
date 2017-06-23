let component = ReasonReact.statelessComponent "RepoItem";

let make repo::(repo: RepoData.repo) _children => {
  ...component,
  render: fun () self =>
    <div className="RepoItem">
      <a href=repo.html_url> <h2> (ReasonReact.stringToElement repo.full_name) </h2> </a>
      (ReasonReact.stringToElement (string_of_int repo.stargazers_count ^ " stars"))
    </div>
};
