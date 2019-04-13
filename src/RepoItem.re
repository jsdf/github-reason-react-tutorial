[@react.component]
let make = (~repo: RepoData.repo) =>
  <div className="RepoItem">
    <a href={repo.html_url}>
      <h2> {ReasonReact.string(repo.full_name)} </h2>
    </a>
    {ReasonReact.string(string_of_int(repo.stargazers_count) ++ " stars")}
  </div>;